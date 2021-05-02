//a simple class to convert sfml keyboard keys to strings
//and vice versa

#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <map>

class KeyStringMapping{
	public:
		//constructor will setup the map
		KeyStringMapping();
	
		//functions will convert based on the map
		sf::Keyboard::Key stringToKey(std::string str);
		std::string keyToString(sf::Keyboard::Key k);
	
	private:
		static std::map<std::string, sf::Keyboard::Key> keyStringMap;
		static std::map<sf::Keyboard::Key, std::string> stringKeyMap;
};
