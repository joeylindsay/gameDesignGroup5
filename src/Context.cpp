#include "Context.hpp"
#include <SFML/Graphics.hpp>

Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, KeyStringMapping& keyMap, int& score)
    : window { window }
    , textures { textures }
    , fonts { fonts }
    , keyMap { keyMap }
    , score { score }
{
}
