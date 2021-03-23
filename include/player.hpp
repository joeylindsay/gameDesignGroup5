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

        int m_Health;
        float m_Speed;
		
		//the delay for the player's time stop ability
		int timeStopCooldown;
		//true if time stop is ready
		bool timeStopReady;

    public:
        player();
        sf::CircleShape m_Player;

        void setPosition();
        sf::FloatRect getPosition();

        sf::Sprite getPlayer();

        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();

        int getHealth();
        void setHealth();
        
        void hit();
		
		//function to check if player special ability is ready for use
		bool isTimeStopReady();
};
}
#endif 
