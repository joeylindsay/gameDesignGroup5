//the main file for the playerView class

#include<playerView.hpp>
#include<iostream>

sf::Texture interceptors::playerView::m_backgroundSpriteTex;
static const float VIEW_HEIGHT = 1080.0f;

interceptors::playerView::playerView(bullet* bullets, sf::RenderWindow* playerWindow, aiView* m_aiView){
	using interceptors::playerView;
	
	//save the window and bullet lists in their local containers
	playerWindowP = playerWindow;
	bulletsP = bullets;
	
	//create the player view object
	m_playerView = sf::View(sf::Vector2f(0.0f,0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	
	//create the player object
	m_player = player();
	//move player to the center of the screen on start
	m_player.setPosition(*playerWindowP);
	//resize the player sprite
	
	
	//create an invisible, untextured sprite for the view to follow
	m_backgroundSpriteTex.loadFromFile("../assets/forest_background.png");
	m_backgroundSprite.setTexture(m_backgroundSpriteTex);
	m_backgroundSprite.setOrigin(m_backgroundSpriteTex.getSize().x / 2.0f, 540.0f);
}

void interceptors::playerView::updateHealth(){
	using interceptors::playerView;
	//TODO
}

void interceptors::playerView::getTimeStop(){
	using interceptors::playerView;
	//TODO
}

int* interceptors::playerView::detectCollisions(){
	using interceptors::playerView;
	//TODO
}

//function to resize the view if the user resizes the screen
void interceptors::playerView::resizeView(){
	
	//save the dimensions of the window
	float xSize = playerWindowP->getSize().x;
	float ySize = playerWindowP->getSize().y;
	
	//if the x width is bigger, scale to y
	if (xSize > ySize){
		float scalefactor = ySize / xSize;
		m_playerView.setViewport(sf::FloatRect((1.0f - scalefactor)/2.0f, 0.0f, scalefactor, 1.0f));
	}else{	//if the y width is bigger, scale to x
		float scalefactor = xSize / ySize;
		m_playerView.setViewport(sf::FloatRect(0.0f, (1.0f - scalefactor)/2.0f, 1.0f, scalefactor));
	}

}

void interceptors::playerView::draw(){
	using interceptors::playerView;
	//clear the window
	playerWindowP->clear(sf::Color::Black);
	
	//set the view
	m_playerView.move(0.0f, 1.0f);
	playerWindowP->setView(m_playerView);
	
	//draw the background
	playerWindowP->draw(m_backgroundSprite);
	
	//draw the player
	playerWindowP->draw(m_player.getPlayer());
	
	//display the window
	playerWindowP->display();
}
