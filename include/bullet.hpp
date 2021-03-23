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
		//set the position of the bullet
		void setStartPosition();
		//set the direction in which the bullet should fire
		void setFireDirection();
		//get the direction the bullet is facing
		sf::Vector2f getFireDirection();
		//spawn and fire the bullet
		void fire();
		//despawn the bullet (on edge of screen or on hit)
		void despawn();
		//set the bullet speed (for the machine gun power-up)
		void setSpeed();
		//get the hitbox of the bullet
		sf::FloatRect getBulletHitbox();
	
	private:
		//the position of the bullet
		sf::Vector2f b_position;
		//the direction of the bullet (in degrees; 180 points straight left, 0 straight right)
		int b_direction;
		//the bullet sprite
		sf::Sprite b_sprite;
		//the bullet speed
		int b_speed;
};
}

#endif
