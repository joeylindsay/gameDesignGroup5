/// \file Application.hpp
/// \author Rui Hou, Joey Lindsay, Harrison Keen, Kathy Ngo
/// \brief Header file for the Application class
/// \date 2021-04-02

#pragma once

#include "Context.hpp"
#include "FontHolder.hpp"
#include "Game.hpp"
#include "TextureHolder.hpp"
#include <SFML/Graphics.hpp>

/// Game application layer which handles initialization, timing, main game loop and shutdown.
class Application {
public:
    Application();
    /// The main game loop.
    void run();

private:
    sf::RenderWindow _window { sf::VideoMode { 768, 1024 }, "Interceptors", sf::Style::Close };
    TextureHolder _textures;
    FontHolder _fonts;
    Context _context;
    Game _gameLogic;
    std::vector<sf::Event> _eventQueue;
};