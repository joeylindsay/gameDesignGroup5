#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

namespace interceptors
{
class player
{
    private:
        sf::Vector2f m_PlayerPosition;
        sf::Sprite m_PlayerSprite;
        static sf::Texture m_PlayerTexture;

        int m_Health;
        float m_Speed;
		
	//the delay for the player's time stop ability
	int timeStopCooldown;
	//true if time stop is ready
	bool timeStopReady;

    public:
        player();

        void setPosition(sf::RenderWindow& window);
        sf::Vector2f getPosition();
        sf::Sprite getPlayer();

        void moveLeft(float deltaMS);
        void moveRight(sf::RenderWindow& window, float deltaMS);
        void moveUp(float deltaMS);
        void moveDown(sf::RenderWindow& window, float deltaMS);

        int getHealth();
        void setHealth(int health);
        
        void gotHit();
		
		//function to check if player special ability is ready for use
		bool isTimeStopReady();
};
}
#endif 
