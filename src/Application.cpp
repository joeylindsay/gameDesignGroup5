/// \file Application.cpp
/// \author Rui Hou, Joey Lindsay, Harrison Keen, Kathy Ngo
/// \brief Source file for the Application class
/// \date 2021-04-02

#include "Application.hpp"

Application::Application()
    : _context { _window, _textures, _fonts }
    , _gameLogic { _context, _eventQueue }
{
}

void Application::run()
{
    sf::Clock clock;
    while (_window.isOpen()) {
        const sf::Time dt { clock.restart() };

        _eventQueue.clear();
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _window.close();
                break;
            } else if (event.type == sf::Event::Resized){
            	_gameLogic.resize();
            }
            _eventQueue.push_back(event);
        }

        _gameLogic.update(dt);
    }
}
