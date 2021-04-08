/*Power up header. A simple floating hitbox,
with a type that indicates the type of power up*/

#ifndef POWERUP_HPP
#define POWERUP_HPP

#include <SFML/Graphics.hpp>

namespace interceptors
{
class powerUp
{
    public:
        powerUp(int type);
        void spawn(sf::RenderWindow& window);
        sf::FloatRect getPosition();
        sf::Sprite getPowerUp();
        bool isSpawned();
        int apply();
        
    private:
        sf::Sprite m_Sprite;
        sf::Texture m_Texture;

        int m_Type;
        bool m_Spawned;
        float m_timeSinceSpawn;
};
}

#endif 
