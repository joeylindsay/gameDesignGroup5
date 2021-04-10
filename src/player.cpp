//main player file

#include <player.hpp>


sf::Texture interceptors::player::m_PlayerTexture;

interceptors::player::player(){
	using interceptors::player;
	m_Health = 100;
	m_Speed = 200;
	
	m_PlayerTexture.loadFromFile("../assets/interceptorsprite.png");
	m_PlayerSprite.setTexture(m_PlayerTexture);
	
	//move the player's origin to the center of the texture
	m_PlayerSprite.setOrigin(m_PlayerTexture.getSize().x / 2.0, m_PlayerTexture.getSize().y / 2.0);
	//scale the sprite. This is the default, and will update on a window resize event
	m_PlayerSprite.scale(0.2f, 0.2f);
}	

void interceptors::player::setPosition(sf::RenderWindow& window){
	using interceptors::player;
	m_PlayerPosition.x = window.getSize().x/2;
	m_PlayerPosition.y = window.getSize().y;
}

sf::Vector2f interceptors::player::getPosition(){
	using interceptors::player;
	return m_PlayerPosition;
}

sf::Sprite interceptors::player::getPlayer(){
	using interceptors::player;
	return m_PlayerSprite;
}

void interceptors::player::moveLeft(float deltaMS){
	using interceptors::player;
	if (m_PlayerPosition.x > 50)
		m_PlayerPosition.x -= m_Speed * deltaMS;

	m_PlayerSprite.setPosition(m_PlayerPosition);
}

void interceptors::player::moveRight(sf::RenderWindow& window, float deltaMS){
	using interceptors::player;
	if (m_PlayerPosition.x < window.getSize().x - 50)
		m_PlayerPosition.x += m_Speed * deltaMS;

	m_PlayerSprite.setPosition(m_PlayerPosition);
}

void interceptors::player::moveUp(float deltaMS){
	using interceptors::player;
	if (m_PlayerPosition.y > 150)
		m_PlayerPosition.y -= m_Speed * deltaMS;

	m_PlayerSprite.setPosition(m_PlayerPosition);
}

void interceptors::player::moveDown(sf::RenderWindow& window, float deltaMS){
	using interceptors::player;
	if (m_PlayerPosition.y < window.getSize().y - 150)
		m_PlayerPosition.y += m_Speed * deltaMS;

	m_PlayerSprite.setPosition(m_PlayerPosition);
}

int interceptors::player::getHealth(){
	using interceptors::player;
	return m_Health;
}

void interceptors::player::setHealth(int health){
	using interceptors::player;
	m_Health = health;
}
        
void interceptors::player::gotHit(){
	using interceptors::player;
	m_Health -= 10;
}
		
//function to check if player special ability is ready for use
bool interceptors::player::isTimeStopReady(){
	using interceptors::player;
	if (timeStopCooldown = 0)
		return true;
	else
		return false;
}
