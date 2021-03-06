/// \file Application.hpp
/// \author Rui Hou, Joey Lindsay, Harrison Keen, Kathy Ngo
/// \brief Header file for the Application class
/// \date 2021-04-02

#pragma once

#include "FontHolder.hpp"
#include "Game.hpp"
#include "KeyStringMapping.hpp"
#include "SoundPlayer.hpp"
#include "MusicPlayer.hpp"
#include "TextureHolder.hpp"
#include <SFML/Graphics.hpp>

/// Game application layer which handles initialization, timing, main game loop and shutdown.
class Application {
public:
    Application();
    /// The main game loop.
    void run();

private:
    sf::RenderWindow _window { sf::VideoMode::getDesktopMode(), "Interceptors" };
    TextureHolder _textures;
    FontHolder _fonts;
    MusicPlayer _music;
    SoundPlayer _sounds;
    Context _context;
    Game _gameLogic;
    KeyStringMapping _keyMap;
    int _score = 0;
    float _worldTop;
    std::vector<sf::Event> _eventQueue;
};
