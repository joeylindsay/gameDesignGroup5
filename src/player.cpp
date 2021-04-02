//main player file

#include <player.hpp>

using interceptors::player;

interceptors::player::player(){
	m_Health = 100;
	m_Speed = 200;

	m_PlayerTexture.loadFromFile("../assets/interceptorsprite.png");
	m_PlayerSprite.setTexture(m_PlayerTexture);

	// m_PlayerSprite.setOrigin(25,100);
}

void interceptors::player::setPosition(sf::RenderWindow& window){
	m_PlayerPosition.x = window.getSize().x/2;
	m_PlayerPosition.y = window.getSize().y;
}

sf::Vector2f interceptors::player::getPosition(){
	return m_PlayerPosition;
}

sf::Sprite interceptors::player::getPlayer(){
	return m_PlayerSprite;
}

void interceptors::player::moveLeft(float deltaMS){
	if (m_PlayerPosition.x > 50)
		m_PlayerPosition.x -= m_Speed * deltaMS;

	m_PlayerSprite.setPosition(m_PlayerPosition);
}

void interceptors::player::moveRight(sf::RenderWindow& window, float deltaMS){
	if (m_PlayerPosition.x < window.getSize().x - 50)
		m_PlayerPosition.x += m_Speed * deltaMS;

	m_PlayerSprite.setPosition(m_PlayerPosition);
}

void interceptors::player::moveUp(float deltaMS){
	if (m_PlayerPosition.y > 150)
		m_PlayerPosition.y -= m_Speed * deltaMS;

	m_PlayerSprite.setPosition(m_PlayerPosition);
}

void interceptors::player::moveDown(sf::RenderWindow& window, float deltaMS){
	if (m_PlayerPosition.y < window.getSize().y - 150)
		m_PlayerPosition.y += m_Speed * deltaMS;

	m_PlayerSprite.setPosition(m_PlayerPosition);
}

int interceptors::player::getHealth(){
	return m_Health;
}

void interceptors::player::setHealth(int health){
	m_Health = health;
}
        
void interceptors::player::gotHit(){
	m_Health -= 10;
}
		
//function to check if player special ability is ready for use
bool interceptors::player::isTimeStopReady(){
	if (timeStopCooldown = 0)
		return true;
	else
		return false;
}
