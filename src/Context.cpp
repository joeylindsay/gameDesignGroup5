#include "Context.hpp"
#include <SFML/Graphics.hpp>

Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, KeyStringMapping& keyMap)
    : window { window }
    , textures { textures }
    , fonts { fonts }
    , keyMap { keyMap }
{
}
