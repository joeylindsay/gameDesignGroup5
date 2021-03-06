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
        Cockpit,
        keyPressPrompt,
        Bogey,
        Flagship,
        StopActive,
        StopInactive,
        IDSize
    };
    /// Returns a reference to the texture by ID.
    TextureHolder();
    sf::Texture& get(ID id);
private:
    std::vector<sf::Texture> textures;
};
