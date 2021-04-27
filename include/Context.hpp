#pragma once

#include "FontHolder.hpp"
#include "TextureHolder.hpp"
#include <SFML/Graphics.hpp>

struct Context
{
    Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts);
    sf::RenderWindow& window;
    TextureHolder& textures;
    FontHolder& fonts;
};
