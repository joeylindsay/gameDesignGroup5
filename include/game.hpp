/*definition of the game class. This is a simple state machine
that keeps track of the game state. It plugs in different game states
that implement different behavior and parts of the game.*/

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <bogey.hpp>
#include <bullet.hpp>
#include <flagship.hpp>
#include <levelOne.hpp>
#include <loseScreen.hpp>
#include <menu.hpp>
#include <options.hpp>
#include <player.hpp>
#include <powerUp.hpp>
#include <screamer.hpp>
#include <winScreen.hpp>

namespace interceptors

{
    class game
    {
        public:
            game();

    private:
			//the main screen updating functions
			//calls a draw option on the level state at the rate of the game speed
            static void run();
			//different functions for each state
            static void menu();
            static void options();
            static void levelOne();
            static void win();
            static void lose();
			static bool isQuitting();
			
			//enumeration of the states
            enum state
            {
                s_menu,
                s_options,
                s_levelOne,
                s_win,
                s_lose,
                s_quit
            };

        private:
			//the current game state
            static sf::Uint32 m_state;
			//the main window that we render in
            static sf::RenderWindow m_window;
			//speed of the game, otherwise known as the deltams
			static sf::Time gameSpeed;
    };
}

#endif
