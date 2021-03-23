/*This is a header for the main game loop
of the first level of the game.*/

#ifndef LEVELONE_HPP
#define LEVELONE_HPP

#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <player.hpp>
#include <bullet.hpp>
#include <screamer.hpp>
#include <bogey.hpp>
#include <flagship.hpp>
#include <powerUp.hpp>

namespace interceptors
{
class levelOne{
	
	public:
		levelOne();
		void show(sf::RenderWindow& window);
		
		//utility function to return the current game score
		int getscore();
		
		//the main game loop function. I expect that this will expand out into
		//multiple functions as development progresses
		void play();
	
	private:
		//the player entity
		interceptors::player player;
		//list of all the screamers onscreen
		interceptors::screamer screamers [25];
		//list of all the bogeys onscreen
		interceptors::bogey bogeys [25];
		//the boss entity
		interceptors::flagship flagship;
		//the player score
		int score;
		
		//additional sprites
		sf::Sprite m_explosionSpr;
		
		//sound variables
		sf::Music backgroundMusic;
		sf::Music bossMusic;
		
		sf::Sound screamerSound;
		sf::Sound bogeySound;
		sf::Sound shootingSound;
		sf::Sound explosionSound;
		
		//window drawing variables
		float m_winsizeX;
        	float m_winsizeY;
        	float m_scaleX;
       	float m_scaleY;
		sf::Sprite background;
		
		//player game settings
		int volume;
		sf::Uint32 moveup;
		sf::Uint32 movedown;
		sf::Uint32 moveleft;
		sf::Uint32 moveright;
		sf::Uint32 shoot;
};
}

#endif
