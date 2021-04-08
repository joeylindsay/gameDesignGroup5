//header for the creation and management of the aiView class
//this is simply a list of sprites on screen and the necessary
//logic to complete the collision detection and movement

#ifndef AIVIEW_HPP
#define AIVIEW_HPP

#include <bogey.hpp>
#include <screamer.hpp>
#include <bullet.hpp>

namespace interceptors
{
	class aiView
	{
		public:
			//constructor. Adds a pointer to list of onscreen bullets
			aiView(bullet* bullets);
			
			//adds a bogey to the list of bogeys onscreen
			void addBogey(bogey newbogey);
			
			//adds a screamer to the list of screamers onscreen
			void addScreamer(screamer newscreamer);
			
			//a function to detect collisions between the sprites.
			//Naiive implementation is fine for our purposes -- check collision between
			//each bullet and each enemy. Returns a list of enemy sprite indecies
			//to remove
			int* detectCollisions();
			
			//a function to step each enemy along its set movement path
			void moveEnemies();
			
			//function to get the list of bogeys
			bogey* getBogeyList();
			
			//funciton to get the list of screamers
			screamer* getScreamerList();
		
		private:
			//list of all the bogeys onscreen
		 	bogey bogeysOnscreen [50];
		 	
		 	//list of all the screamers onscreen
		 	screamer screamersOnscreen [50];
		 	
			//pointer to the list of all onscreen bullets
			bullet* bullets;
	};
}
#endif
