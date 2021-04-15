//the main file for the playerView class

#include<playerView.hpp>
#include<iostream>

sf::Texture interceptors::playerView::m_backgroundSpriteTex;
static const float VIEW_HEIGHT = 1080.0f;

interceptors::playerView::playerView(bulletList* bullets, sf::RenderWindow* playerWindow, aiView* m_aiView, player* player){
	using interceptors::playerView;
	
	//save the window and bullet lists in their local containers
	playerWindowP = playerWindow;
	bulletsP = bullets;
	
	//create the player view object
	m_playerView = sf::View(sf::Vector2f(0.0f,0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	
	//create the player object
	playerP = player;
	
	//load in the background
	m_backgroundSpriteTex.loadFromFile("../assets/forest.png");
	m_backgroundSprite.setTexture(m_backgroundSpriteTex);
	m_backgroundTexHeight = int(m_backgroundSpriteTex.getSize().y);
	m_backgroundSprite.setOrigin(m_backgroundSpriteTex.getSize().x / 2.0f, m_backgroundTexHeight - (VIEW_HEIGHT/2));
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
	
	//loop the view if we've reached the end of the background texture
	if ((m_playerView.getCenter().y - (VIEW_HEIGHT)) < (-m_backgroundTexHeight)){
		playerP->setPosition(playerP->getPosition().x, (playerP->getPosition().y - m_playerView.getCenter().y));
		bulletNode* curNode = bulletsP->head->next;
		while (curNode->next != NULL){
			curNode->m_bullet.setPosition(curNode->m_bullet.getPosition().x, (curNode->m_bullet.getPosition().y - m_playerView.getCenter().y));
			curNode = curNode->next;
		}
		m_playerView.setCenter(0.0f, 0.0f);
	//otherwise just scroll the view
	}else{
		m_playerView.move(0.0f, -0.5f);
		playerP->move(0.0f, -0.5f);
	}
	playerWindowP->setView(m_playerView);
	
	//draw the background
	playerWindowP->draw(m_backgroundSprite);
	
	//define the view location
	sf::FloatRect viewRect = sf::FloatRect((m_playerView.getCenter().x - (VIEW_HEIGHT/2)), (m_playerView.getCenter().y - (VIEW_HEIGHT/2)), VIEW_HEIGHT, VIEW_HEIGHT);
	
	//draw all the bullets onscreen
	bulletNode* curNode = bulletsP->head->next;
	
	for (int i=0; i < bulletsP->length; i++){
		//check if the bullet is visible
		if (viewRect.contains(curNode->m_bullet.getPosition())){
			//draw the bullet
			playerWindowP->draw(curNode->m_bullet.b_sprite);
		}
		//if it's not, then pop it from the list
		else {
			bulletsP->popNode(i);
		}
		curNode = curNode->next;
	}
	
	//keep the player within the y scope of the view
	if (playerP->getPlayer().getGlobalBounds().top < viewRect.top){
		playerP->setPosition(playerP->getPosition().x, (viewRect.top + (playerP->height/2)));
	} else if ((playerP->getPlayer().getGlobalBounds().top + playerP->height) > (viewRect.top + viewRect.height)){
		playerP->setPosition(playerP->getPosition().x, (viewRect.top + (VIEW_HEIGHT) - (playerP->height/2)));
	}
	//keep the player within the x scope of the view
	if (playerP->getPlayer().getGlobalBounds().left < viewRect.left){
		playerP->setPosition(viewRect.left + (playerP->width/2), playerP->getPosition().y);
	} else if ((playerP->getPlayer().getGlobalBounds().left + playerP->width) > (viewRect.left + viewRect.width)){
		playerP->setPosition((viewRect.left + VIEW_HEIGHT) - (playerP->width/2), playerP->getPosition().y);
	}
	
	//draw the player
	playerWindowP->draw(playerP->getPlayer());
	
	//display the window
	playerWindowP->display();
}
