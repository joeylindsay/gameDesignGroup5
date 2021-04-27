/*Header for the screamer enemey
Rather than using a set speed, the screamer will run on a script
that will change its position and fire based on a set series
of vectors that will apply overtime to its current position.*/

#ifndef SCREAMER_HPP
#define SCREAMER_HPP

#include <SFML/Graphics.hpp>
#include <bullet.hpp>

namespace interceptors
{
class screamer {
	public:
		//draw the enemy onto the screen (spawn)
		screamer(sf::RenderWindow& window);
		//for when the enemy is killed by the player
		void death();
		//for when the enemy flies offscreen
		//void despawn();
		//get the current position of the enemy
		sf::Vector2f getPosition();
		//set the position of the enemy
		void setPosition(float a, float b);
		//function for determining when the enemy fires
		void shoot();
		//function for when the enemy takes a hit
		void takeHit();
		//function for retrieving the health of the enemy
		int getHealth();
		//function for retrieving the current path step of the enemy
		sf::Vector2f getPath();
		//function for retrieving the current path step of the enemy
		sf::Vector2f getNextMovement();
		//function for updating the enemy's position
		void move();
	
	private:
		//integer recording the enemy's current health
		int health;
		//vector recording the enemy's current position
		sf::Vector2f position;
        //vector recording size of window, used in determining degree of motion
        sf::Vector2u window_size;
		/*array of vectors indicating the path that the enemy is supposed to follow.
		my thinking is that since the enemies are going to follow 
		set paths with random noise, we don't need a set speed. We can use an array
		of vectors that state how far the enemy is supposed to move, and in which
		direction. It can then apply these transformations to its current position
		sequentially, with noise added by the main game loop*/
		sf::Vector2f path [50];
		//fire steps are a list of positions inside of the path list during which
		//the screamer will fire
		int fireSteps [8];
		//pathPosition is the current position in the movement path
		int pathPosition;
		//the enemy sprite
		sf::Sprite enemySprite;
};
}
#endif
