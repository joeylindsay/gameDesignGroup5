#include "Context.hpp"

Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, MusicPlayer& music, SoundPlayer& sounds, KeyStringMapping& keyMap, int& score, float& worldTop)
    : window { window }
    , textures { textures }
    , fonts { fonts }
    , music { music }
    , sounds { sounds }
    , keyMap { keyMap }
    , score { score }
    , worldTop { worldTop }
{
}
