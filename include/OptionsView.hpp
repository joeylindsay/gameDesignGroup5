/*The header file for the options menu.
The main options program will read in options from an 
XML file, which can be overwritten by input from the
player in this menu*/

#pragma once

#include "Context.hpp"
#include "GameStateID.hpp"
#include "GameView.hpp"
#include "Command.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <map>
#include <vector>
#include "../RapidXML/rapidxml_ext.hpp"

class OptionsView : public GameView
{
	public:
		//base constructor, will setup the whole menu and draw it to screen
		OptionsView(Context& context, sf::View& view);
		//update the screen
		void update(sf::Time dt, GameStateID state, const sf::FloatRect& worldBounds, std::vector<Command>& commandQueue) override;
		//reload all of the text onscreen
		void reloadText();
		//write the new key into the xml file
		void writeFile();
		//dummy functions
		void remapKeys() override;
		void stopIndic(bool b) override;
	private:
		//handle the input to the view
		void handleInput(std::vector<Command>& commandQueue);
		
		//containers to hold the context and view
		Context& _context;
		sf::View& _view;
		
		//map to hold the rectangles
		std::map<int, sf::RectangleShape> recVec;
		
		//vector to hold the strings that show onscreen
		std::vector<std::string> _stringVec;
			
		//window drawing variables
		float m_scale;
		float m_winsizeX;
		float m_winsizeY;
		sf::Sprite _optionsSprite;
		sf::Sprite _keyPressSprite;
		
		//variables to store the different onscreen elements
		sf::Text _up_button;
    	sf::Text _down_button;
    	sf::Text _left_button;
    	sf::Text _right_button;
    	sf::Text _shoot_button;
    	sf::Text _time_stop_button;
    	sf::Text _back_button;
    	
    	//rectangles to sit behind the onscreen text
    	sf::RectangleShape _upRect;
    	sf::RectangleShape _downRect;
    	sf::RectangleShape _leftRect;
    	sf::RectangleShape _rightRect;
    	sf::RectangleShape _shootRect;
    	sf::RectangleShape _timeStopRect;
    	sf::RectangleShape _backRect;
    	
};
