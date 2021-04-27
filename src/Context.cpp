#include "Context.hpp"
#include <SFML/Graphics.hpp>

Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts)
    : window { window }
    , textures { textures }
    , fonts { fonts }
{
}