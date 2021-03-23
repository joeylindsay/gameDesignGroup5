//win screen header file, a simple box
//that shows a picture and the player score
#ifndef winSCREEN_HPP
#define winSCREEN_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

namespace interceptors
{
    class winScreen
    {
        public:
            winScreen(int score);

            void show(sf::RenderWindow& window);

        private:
            int score;
			sf::Sprite winScreenSprite;
    };
}

#endif
