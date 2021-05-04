#pragma once

#include "FontHolder.hpp"
#include "TextureHolder.hpp"
#include "KeyStringMapping.hpp"
#include "MusicPlayer.hpp"
#include "SoundPlayer.hpp"
#include <SFML/Graphics.hpp>

struct Context
{
    Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, MusicPlayer& music, SoundPlayer& sounds, KeyStringMapping& keyMap, int& score, float& worldTop);
    sf::RenderWindow& window;
    TextureHolder& textures;
    FontHolder& fonts;
    MusicPlayer& music;
    SoundPlayer& sounds;
    KeyStringMapping& keyMap;
    int& score;
    float& worldTop;
};
