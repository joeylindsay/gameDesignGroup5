//header for the creation and management of the playerView class
//this is going to include a list of sprites on the screen,
//the main game window, and will capture keyboard input from
//the player

#ifndef PLAYERVIEW_HPP
#define PLAYERVIEW_HPP

#include <SFML/Window.hpp>
#include <player.hpp>
#include <aiView.hpp>
#include <bullet.hpp>
#include <bogey.hpp>
#include <screamer.hpp>

namespace interceptors
{
	class playerView
	{
		public:
			//basic player view constructor
			playerView(bullet* bullets, sf::RenderWindow* playerWindow, aiView* m_aiView);
			
			//checks the player's health and updates the corresponding HUD element
			void updateHealth();
			
			//checks the player's times top ability status and updates the corresponding HUD element
			void getTimeStop();
			
			//detect collisions between the player and bullets
			int* detectCollisions();
			
			//redraws the entire screen with all sprites on it
			void draw();
		
		private:
			//the window that we will be drawing in
			sf::RenderWindow* playerWindowP;
			
			//pointer to the list of all onscreen bullets
			bullet* bulletsP;
			
			//variable to store the player instance
			player m_player;
			
			//pointer to the list of screamers
			bogey* bogeyP;
			
			//pointer to the list of bogeys
			screamer* screamerP;
	};
}
#endif
