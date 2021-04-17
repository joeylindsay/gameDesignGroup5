//main power up file
#include <powerUp.hpp>

interceptors::powerUp::powerUp(int type){
	using interceptors::powerUp;
	m_Type = type;
	
	if (m_Type = 1)
	{	
		m_Texture.loadFromFile("../assets/fastshot.png");
		m_Sprite.setTexture(m_Texture);
	}

	else
	{
		m_Texture.loadFromFile("../assets/spreadshot.png");
		m_Sprite.setTexture(m_Texture);
	}

	// m_Sprite.setOrigin(10,10);
}

void interceptors::powerUp::spawn(sf::RenderWindow& window){
	using interceptors::powerUp;
	srand((int)time(0) / m_Type);
	int x = (rand() % window.getSize().x); 
   	srand((int)time(0) * m_Type); 
   	int y = (rand() % window.getSize().y); 
 
   	m_timeSinceSpawn = 0; 
   	m_Spawned = true; 
 
   	m_Sprite.setPosition(x, y);
}

sf::FloatRect interceptors::powerUp::getPosition(){
	using interceptors::powerUp;
	return m_Sprite.getGlobalBounds();
}

sf::Sprite interceptors::powerUp::getPowerUp(){
	using interceptors::powerUp;
	return m_Sprite;
}

bool interceptors::powerUp::isSpawned(){
	using interceptors::powerUp;
	return m_Spawned;
}

int interceptors::powerUp::apply(){
	using interceptors::powerUp;
	m_Spawned = false;
}
