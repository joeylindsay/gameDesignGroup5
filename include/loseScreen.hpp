//very simple header file for the lose screen
//It just shows a basic picture and your score
#ifndef LOSESCREEN_HPP
#define LOSESCREEN_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

namespace interceptors
{
    class loseScreen
    {
        public:
            loseScreen(int score);

            void show(sf::RenderWindow& window);

        private:
            int score;
			sf::Sprite loseScreenSprite;
    };
}

#endif
