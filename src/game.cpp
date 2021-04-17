//main game loop file
#include <game.hpp>
#include <iostream>

//instantiate static member variables
sf::Uint32 interceptors::game::m_state;
sf::RenderWindow interceptors::game::m_window;
sf::Texture interceptors::game::m_bulletTexture;
//setup the game running time
sf::Time interceptors::game::gameSpeed = sf::seconds(0.0016f);
//setup the pause boolean
bool interceptors::game::isPaused = false;

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
	
	//instantiate the player object
	player m_player = player();
	
	//setup the bullet time gap
	sf::Time bulletGap = sf::seconds(0.15f);
	
	//load the bullet texture
	m_bulletTexture.loadFromFile("../assets/bullet.png");
	
	//create a linked list to contain all of the bullets onscreen
	bulletList m_bulletList = bulletList();
	bulletNode* curNode = m_bulletList.head;
	
	//instantiate an ai view
	aiView m_aiView(&m_bulletList);
		
	//instantiate a player view
	playerView m_playerView(&m_bulletList, &m_window, &m_aiView, &m_player);
	
	//call the resize function to correct screen stretching
	m_playerView.resizeView();
	
	//start the necessary game clocks
	sf::Clock clock;
	sf::Clock bulletClock;
	sf::Time elapsedTime;
	sf::Time elapsedBulletTime;
	
	//create an event container
	sf::Event event;
	
	//movement vector
	sf::Vector2f movementVector;
	
	//main game loop
	while (m_state == state::s_levelOne){
		//update the times
		elapsedTime = clock.getElapsedTime();
		elapsedBulletTime = bulletClock.getElapsedTime();
		
		//reset the bullet node
		curNode = m_bulletList.head;
				
		//poll the window for events
		if (m_window.pollEvent(event)){
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
			//We check each key pressed and add them to a movment vector
			//move up
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
				movementVector.y = -3.0f;
			//move down
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				movementVector.y += 3.0f;
			} 
			//move left
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				movementVector.x = -3.0f;
			//move right
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				movementVector.x += 3.0f;
			} 
			
			//halve the speed for diagonal movement
			if (movementVector.x != 0.0f && movementVector.y != 0.0f){
				movementVector.x = movementVector.x/1.5f;
				movementVector.y = movementVector.y/1.5f;
			}
			
			//apply the movement
			m_player.move(movementVector.x, movementVector.y);
			movementVector.x = 0.0f;
			movementVector.y = 0.0f;
			
			//spawn bullets
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && elapsedBulletTime >= bulletGap){
				m_bulletList.pushNode(&m_bulletTexture, 5.0f, (m_player.getPosition().x - 2.5f), (m_player.getPosition().y + 8.0f));
				//debug linked list m_bulletList.toConsole();
				elapsedBulletTime = bulletClock.restart();
			}
			
			//update the position of all the bullets onscreen
			while (curNode->next != NULL){
				curNode->m_bullet.move();
				curNode = curNode->next;
			}
			
			//check for a pause input
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				isPaused = true;
				
				//wait until the user lifts up from the escape key
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
				
				while (isPaused){
					pauseGame(m_playerView);
				}
			} 
			//draw the view
			m_playerView.draw();
			elapsedTime = clock.restart();
		}
	}
}

void interceptors::game::pauseGame(playerView m_playerView){
	using interceptors::game;
	//create an event container
	sf::Event event;
	
	//check for window events
	if (m_window.pollEvent(event)){
		switch (event.type){
			//if they close the window, close the game
			case sf::Event::Closed:
			{
				m_state = state::s_quit;
				isPaused = false;
			}break;
			//resize the window
			case sf::Event::Resized:
			{
				m_playerView.resizeView();
				m_playerView.draw();
			}break;
		}
	}
	
	//check if the user is trying to leave the paused state
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
		//wait until the user lifts up from the escape key
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
		isPaused = false;
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
