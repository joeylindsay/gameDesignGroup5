#include "TextureHolder.hpp"

TextureHolder::TextureHolder()
    : textures(static_cast<size_t>(ID::IDSize))
{
    const std::vector<std::string> filenames {
        "title_background.png",
        "jungle_background.png",
        "interceptor_aircraft.png",
        "bullet.png",
        "enemy_bullet.png",
        "screamer.png",
        "cockpit.png",
        "keyPressPrompt.png",
        "bogey.png",
        "flagship.png",
        "stopActive.png",
        "stopInactive.png"
    };
    for (int i { 0 }; i < textures.size(); ++i)
        if (!textures[i].loadFromFile("../assets/" + filenames[i]))
            throw std::runtime_error("TextureHolder: Failed to load " + filenames[i]);
}

sf::Texture& TextureHolder::get(ID id)
{
    return textures[static_cast<size_t>(id)];
}
