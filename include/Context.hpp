#pragma once

#include "FontHolder.hpp"
#include "TextureHolder.hpp"
#include "KeyStringMapping.hpp"
#include <SFML/Graphics.hpp>

struct Context
{
    Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, KeyStringMapping& keyMap, int& score);
    sf::RenderWindow& window;
    TextureHolder& textures;
    FontHolder& fonts;
    KeyStringMapping& keyMap;
    int& score;
};
