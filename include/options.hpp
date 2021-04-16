/*The header file for the options menu.
The main options program will read in options from an 
XML file, which can be overwritten by input from the
player in this menu*/

#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdlib.h>

namespace interceptors
{
	class options
	{
		public:
			//base constructor, will setup the whole menu and draw it to screen
			options();
			void handleInput(sf::Event event);
			//function to show the options on the main window passed by the game file
			void show(sf::RenderWindow& window);
			
		
		private:
			float volume;
			std::string volumeup;
            std::string volumedown;

			std::string moveup;
            std::string movedown;
            std::string moveleft;
            std::string moveright;

            std::string shoot;
			
			//window drawing variables
			float m_scale;
			float m_winsizeX;
			float m_winsizeY;
			sf::Sprite optionsSprite;
	};
}

#endif
