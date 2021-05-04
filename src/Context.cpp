#include "Context.hpp"
#include <SFML/Graphics.hpp>

Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, MusicPlayer& music, KeyStringMapping& keyMap, int& score, float& worldTop)
    : window { window }
    , textures { textures }
    , fonts { fonts }
    , music { music }
    , keyMap { keyMap }
    , score { score }
    , worldTop { worldTop }
{
}
