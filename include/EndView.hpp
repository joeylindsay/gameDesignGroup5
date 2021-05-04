/// \file EndView.hpp
/// \author Rui Hou, Joey Lindsay, Harrison Keen, Kathy Ngo
/// \brief Header file for the GameStateID enum
/// \date 2021-04-02

#pragma once

#include "Context.hpp"
#include "Command.hpp"
#include "GameStateID.hpp"
#include "Aircraft.hpp"
#include "GameView.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class EndView : public GameView {
public:
    EndView(Context& context, sf::View& view);
    //function to update the screen
    void update(sf::Time dt, GameStateID state, const sf::FloatRect& worldBounds, std::vector<Command>& commandQueue) override;
private:
    //function to capture mouse input
    void handleInput(std::vector<Command>& commandQueue);

    //containers for the shared elements
    Context& _context;
    sf::View& _view;

    //containers for all of the onscreen menu view elements
    sf::Text _endText;
    sf::Text _scoreText;
    sf::RectangleShape _fillRect;
};

