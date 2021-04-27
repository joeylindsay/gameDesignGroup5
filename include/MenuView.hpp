#pragma once

#include "Context.hpp"
#include "Command.hpp"
#include "Game.hpp"
#include "GameStateID.hpp"
#include "GameView.hpp"
#include <SFML/Graphics.hpp>

class MenuView : public GameView {
public:
    MenuView(Context& context);
    void update(sf::Time dt, GameStateID state, const sf::FloatRect& worldBounds, std::vector<Command>& commandQueue) override;

private:
    Context& _context;
    sf::Sprite _backgroundSprite;
    sf::Text _titleText;
    sf::RectangleShape _startButton;
    sf::Text _startButtonText;
};
