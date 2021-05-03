#pragma once

#include "FontHolder.hpp"
#include "TextureHolder.hpp"
#include "KeyStringMapping.hpp"
#include <SFML/Graphics.hpp>

struct Context
{
    Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, KeyStringMapping& keyMap);
    sf::RenderWindow& window;
    TextureHolder& textures;
    FontHolder& fonts;
    KeyStringMapping& keyMap;
};
