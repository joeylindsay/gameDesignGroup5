//header for the creation and management of the playerView class
//this is going to include a list of sprites on the screen,
//the main game window, and will capture keyboard input from
//the player

#ifndef PLAYERVIEW_HPP
#define PLAYERVIEW_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

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
			playerView(bulletList* bullets, sf::RenderWindow* playerWindow, aiView* m_aiView, player* playerP);
			
			//checks the player's health and updates the corresponding HUD element
			void updateHealth();
			
			//checks the player's times top ability status and updates the corresponding HUD element
			void getTimeStop();
			
			//detect collisions between the player and bullets
			int* detectCollisions();
			
			//function to resize the view when the user changes the screen size
			void resizeView();
			
			//redraws the player
			void draw();
		
		private:
			//the window that we will be drawing in
			sf::RenderWindow* playerWindowP;
			
			//pointer to the list of all onscreen bullets
			bulletList* bulletsP;
			
			//variable to store the player instance
			player* playerP;
			
			//pointer to the list of screamers
			bogey* bogeyP;
			
			//pointer to the list of bogeys
			screamer* screamerP;
			
			//variable to store the player view
			sf::View m_playerView;
			
			//create the background sprite
			sf::Sprite m_backgroundSprite;
			
			//save the texture for the background sprite
			static sf::Texture m_backgroundSpriteTex;
			
			//save the background texture height
			int m_backgroundTexHeight;
			
			//save the view height
			int m_playerViewHeight;
			
			//save the view width
			int m_playerViewWidth;
	};
}
#endif
