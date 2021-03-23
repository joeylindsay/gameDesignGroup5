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
        void spawn();
        sf::FloatRect getPosition();
        sf::Sprite getPlayer();
        bool isSpawned();
        int apply();
        
    private:
        sf::Sprite m_Sprite;
        int m_Type;
        bool m_Spawned;
        float m_timeSinceSpawn;
        float m_timeSinceDeSpawn;
        float m_SecondsToAppear; 
        float m_SecondsToWait;

    
};
}

#endif 
