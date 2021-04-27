#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

/// Texture resource holder. Load every texture at initialization.
class TextureHolder
{
public:
    enum class ID {
        TitleBackground,
        JungleBackground,
        InterceptorAircraft,
        Bullet,
        EnemyBullet,
        Screamer,
        IDSize
    };
    /// Returns a reference to the texture by ID.
    TextureHolder();
    sf::Texture& get(ID id);
private:
    std::vector<sf::Texture> textures;
};
