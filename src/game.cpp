//main game loop file
#include <game.hpp>
#include <iostream>

//instantiate static member variables
sf::Uint32 interceptors::game::m_state;
sf::RenderWindow interceptors::game::m_window;
//setup the game running time
sf::Time interceptors::game::gameSpeed = sf::seconds(0.0016f);

interceptors::game::game(){
	using interceptors::game;
	
	//setup the main game window
	sf::VideoMode mode = sf::VideoMode::getDesktopMode();
	m_window.create(mode, "interceptors");
	
	//instantiate the title state
	m_state = state::s_title;
	
	//REMOVE THIS WHEN WE'RE DONE WITH THE TITLE SCREEN
	//THIS LINE AUTOMATICALLY SHIFTS THE GAME LOGIC
	//DIRECTLY INTO THE MAIN GAME WITH NO TITLE
	m_state = state::s_levelOne;
	
	//start the run loop
	while(!isQuitting()){
		run();
	}
	m_window.close();
}

//a simple switch statement to run each of the different
//state functions
void interceptors::game::run(){
	using interceptors::game;
	switch(m_state)
	{
		case state::s_title:
		{
			title();
		} break;
		case state::s_menu:
		{
			menu();
		} break;
		case state::s_levelOne:
		{
			levelOne();
		} break;
		case state::s_win:
		{
			win();
		} break;
		case state::s_lose:
		{
			lose();
		} break;
		case state::s_options:
		{
			options();
		} break;
		
		default:
			std::cerr<<"The game encountered an unexpected error"<<std::endl;
			m_state = state::s_quit;
	}
}
//different functions for each state
void interceptors::game::title(){
	using interceptors::game;
	//TODO
}
void interceptors::game::menu(){
	using interceptors::game;
	//TODO
}
void interceptors::game::options(){
	using interceptors::game;
	//TODO
}
void interceptors::game::levelOne(){
	using interceptors::game;
	
	//list of all bullets on screen
	bullet bullets [50];
	
	//instantiate an ai view
	aiView m_aiView(bullets);
		
	//instantiate a player view
	playerView m_playerView(bullets, &m_window, &m_aiView);
	
	//start the time elapsed clock
	sf::Clock clock;
	sf::Time elapsedTime;
	
	//create an event container
	sf::Event event;
	
	//main game loop
	while (m_state == state::s_levelOne){
		elapsedTime = clock.getElapsedTime();
		
		//poll the window for events
		while (m_window.pollEvent(event)){
			switch (event.type){
				//if they close the window, close the game
				case sf::Event::Closed:
				{
					m_state = state::s_quit;
				}break;
				//if they resize the window, run the reisize functions
				case sf::Event::Resized:
				{
					m_playerView.resizeView();
				}break;
			}
		}
		//update the game in real time
		if(elapsedTime >= gameSpeed){
			m_playerView.draw();
			elapsedTime = clock.restart();
		}
	}
}
void interceptors::game::win(){
	using interceptors::game;
	//TODO
}
void interceptors::game::lose(){
	using interceptors::game;
	//TODO
}
//return true if the user quits the game
bool interceptors::game::isQuitting(){
	using interceptors::game;
	return m_state == state::s_quit;
}
