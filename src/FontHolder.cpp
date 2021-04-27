#include "FontHolder.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

FontHolder::FontHolder()
    : _fonts(2)
{
    const std::vector<std::string> filenames {
        "ArcadeClassic.ttf",
        "Sansation.ttf"
    };
    for (int i { 0 }; i < _fonts.size(); ++i)
        if (!_fonts[i].loadFromFile("../assets/" + filenames[i]))
            throw std::runtime_error("FontHolder: Failed to load " + filenames[i]);
}

sf::Font& FontHolder::get(ID id)
{
    return _fonts[static_cast<size_t>(id)];
}
