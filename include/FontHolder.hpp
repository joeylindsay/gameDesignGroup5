#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

/// Font resource holder. Load every font at initialization.
class FontHolder
{
public:
    enum class ID {
        Arcade,
        Sandation
    };
    FontHolder();
    /// Returns a reference to the font by ID.
    sf::Font& get(ID id);
private:
    std::vector<sf::Font> _fonts;
};
