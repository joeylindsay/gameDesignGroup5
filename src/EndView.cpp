#include "EndView.hpp"

//constructor to setup all of the necessary elements
EndView::EndView(Context& context, sf::View& view)
        : GameView {}
        , _context { context }
        , _endText { "GAME OVER!", _context.fonts.get(FontHolder::ID::Arcade), 100 }
        , _scoreText { "", _context.fonts.get(FontHolder::ID::Arcade), 100 }
        , _restartText { "PRESS  ENTER  TO  RESTART", _context.fonts.get(FontHolder::ID::Arcade), 59 }
        , _view { view }
{

    _endText.setFillColor(sf::Color::Yellow);
    _scoreText.setFillColor(sf::Color::Yellow);
    _restartText.setFillColor(sf::Color::Yellow);

}

//handle the return to the menu screen
void EndView::handleInput(std::vector<Command>& commandQueue){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        commandQueue.push_back(Command { Command::Type::Menu });
    }
}

//update the screen
void EndView::update(sf::Time dt, GameStateID state, const sf::FloatRect& worldBounds, std::vector<Command>& commandQueue)
{
	_scoreText.setPosition(300, _context.worldTop + 350);
	_endText.setPosition(300, _context.worldTop + 250);
	_restartText.setPosition(200, _context.worldTop + 650);
	_scoreText.setString("SCORE  " + std::to_string(_context.score));
    handleInput(commandQueue);
    //redraw all window elements
    _context.window.clear();
    _context.window.draw(_restartText);
    _context.window.draw(_endText);
    _context.window.draw(_scoreText);
}

//dummy functions
void EndView::remapKeys(){}
void EndView::stopIndic(bool b){}
