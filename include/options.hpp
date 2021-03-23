/*The header file for the options menu.
The main options program will read in options from an 
XML file, which can be overwritten by input from the
player in this menu*/

#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

namespace interceptors
{
	class options
	{
		public:
			//base constructor, will setup the whole menu and draw it to screen
			options();
			//function to show the options on the main window passed by the game file
			void show(sf::RenderWindow& window);
			
		
		private:
			int volume;
			sf::Uint32 moveup;
			sf::Uint32 movedown;
			sf::Uint32 moveleft;
			sf::Uint32 moveright;
			sf::Uint32 shoot;
			
			//window drawing variables
			float m_scale;
           		float m_winsizeX;
            		float m_winsizeY;
			sf::Sprite optionsSprite;
	};
}

#endif
