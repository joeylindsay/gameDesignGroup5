/* The bullet class header. The bullet class is relatively simple - 
it is simply a position, a direction, a speed, and a sprite.
The main game loop will keep a list of bullets on the screen,
and update them each individually by moving them along their set direction*/
#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>

namespace interceptors
{
class bullet{
	public:
		//dummy constructor to make the compiler happy
		bullet();
		//the main constructor
		bullet(sf::Texture* bulletTex, int speed, sf::Vector2f position);
		//set the position of the bullet
		void setPosition(float start_x, float start_y);
		//get the position of the bullet
		sf::Vector2f getPosition();
		//set the direction in which the bullet should fire
		void setDirection(float angle);
		//get the direction the bullet is facing
		void move();
		//despawn the bullet (on edge of screen or on hit)
		sf::FloatRect getBulletHitbox();
		//the direction of the bullet (in degrees; 180 points straight left, 0 straight right)
		float b_direction;
		//the speed that the bullet is travelling
		int b_speed;
		//the bullet sprite
		sf::Sprite b_sprite;
	
	private:
		//the position of the bullet
		sf::Vector2f b_position;
};
}

#endif
