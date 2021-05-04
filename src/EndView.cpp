#include "EndView.hpp"

//constructor to setup all of the necessary elements
EndView::EndView(Context& context, sf::View& view)
        : GameView {}
        , _context { context }
        , _endText { "GAME OVER!", _context.fonts.get(FontHolder::ID::Arcade), 100 }
        //, _scoreText { "SCORE:", _context.fonts.get(FontHolder::ID::Arcade), 100 }
        , _view { view }
{

    _endText.setPosition(_view.getCenter().x - 425, _view.getCenter().y + 350);
    _endText.setFillColor(sf::Color::White);

    _fillRect.setSize(_view.getSize());
    _fillRect.setFillColor(sf::Color::Green);

//    _scoreText.setPosition(_view.getCenter().x + 75, _view.getCenter().y + 350);
//    _scoreText.setFillColor(sf::Color::White);

}

void EndView::handleInput(std::vector<Command>& commandQueue){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        commandQueue.push_back(Command { Command::Type::Menu });
    }
}

//update the screen
void EndView::update(sf::Time dt, GameStateID state, const sf::FloatRect& worldBounds, std::vector<Command>& commandQueue)
{
    handleInput(commandQueue);
    //redraw all window elements
    sf::RenderWindow& window { _context.window };
    window.clear();
    window.draw(_fillRect);
    window.draw(_endText);
    //window.draw(_scoreText);
}
