//a simple driver program to import all of the necessary headers
//in order and instantiate the game

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
#include <aiView.hpp>
#include <playerView.hpp>
#include <game.hpp>


int main()
{
    try
    {
        interceptors::game startGame = interceptors::game();
    }
    catch(std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}
