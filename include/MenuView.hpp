#pragma once

#include "Context.hpp"
#include "Command.hpp"
#include "GameStateID.hpp"
#include "Aircraft.hpp"
#include "GameView.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class MenuView : public GameView {
public:
    MenuView(Context& context, sf::View& view);
    //function to update the screen
    void update(sf::Time dt, GameStateID state, const sf::FloatRect& worldBounds, std::vector<Command>& commandQueue) override;
	
private:
	//function to capture mouse input
	void handleInput(std::vector<Command>& commandQueue);
	
	//containers for the shared elements
    Context& _context;
    sf::View& _view;
    
    //containers for all of the onscreen menu view elements
    sf::Sprite _backgroundSprite;
    sf::Text _optionsText;
    sf::Text _startText;
    sf::RectangleShape _startRect;
    sf::RectangleShape _optionsRect;
};
