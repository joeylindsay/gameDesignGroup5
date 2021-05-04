#pragma once

#include "Context.hpp"
#include "Command.hpp"
#include "GameStateID.hpp"
#include <SFML/Graphics.hpp>

class GameView
{
public:
    GameView();
    virtual void update(sf::Time dt, GameStateID state, const sf::FloatRect& worldBounds, std::vector<Command>& commandQueue) = 0;
    virtual void remapKeys() = 0;
};
