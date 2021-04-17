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
        
        float height;
        float width;

        void setPosition(float x, float y);
        sf::Vector2f getPosition();
        sf::Sprite getPlayer();

        void move(float x, float y);

        int getHealth();
        void setHealth(int health);
        
        void gotHit();
		
	//function to check if player special ability is ready for use
	bool isTimeStopReady();
};
}
#endif 
