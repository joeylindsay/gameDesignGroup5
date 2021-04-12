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
	m_PlayerSprite.setOrigin(m_PlayerTexture.getSize().x / 2.0f, m_PlayerTexture.getSize().y / 2.0f);
	//scale the sprite. This is the default, and will update on a window resize event
	m_PlayerSprite.scale(0.2f, 0.2f);
	//set the player height
	height = m_PlayerSprite.getGlobalBounds().height;
	width = m_PlayerSprite.getGlobalBounds().width;
}	

void interceptors::player::setPosition(float x, float y){
	using interceptors::player;
	//save the local position coordinates
	m_PlayerPosition.x = x;
	m_PlayerPosition.y = y;
	
	//apply them to the player sprite
	m_PlayerSprite.setPosition(x,y);
}

sf::Vector2f interceptors::player::getPosition(){
	using interceptors::player;
	return m_PlayerPosition;
}

sf::Sprite interceptors::player::getPlayer(){
	using interceptors::player;
	return m_PlayerSprite;
}

void interceptors::player::move(float x, float y){
	using interceptors::player;
	m_PlayerPosition.x += x;
	m_PlayerPosition.y += y;
	m_PlayerSprite.move(x, y);
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
