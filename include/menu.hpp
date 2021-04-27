/*The header for the menu state. A simple state
machine with various choices*/

#ifndef TITLE_HPP
#define TITLE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

namespace interceptors
{
	class menu
	{
		public:
			//base constructor, will setup the whole menu and draw it to screen
			menu();
            void handleInput(sf::Event event);
			//function to show the menu on the main window passed by the game file
			void show(sf::RenderWindow& window);
			
			//menu choices
			enum choice
			{
				m_uninitialized, //the first state for when the menu is not finished setting up
				m_play,
				m_info,
				m_options,
				m_quit
			};
		
		private:
			choice m_choice;
			
			//window drawing variables
			float m_scale;
			float m_winSizeX;
			float m_winSizeY;
			sf::Sprite menuScreen;
	};

}
#endif
