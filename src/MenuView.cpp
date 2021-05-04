#include "MenuView.hpp"

//constructor to setup all of the necessary elements
MenuView::MenuView(Context& context, sf::View& view)
    : GameView {}
    , _context { context }
    , _backgroundSprite { _context.textures.get(TextureHolder::ID::TitleBackground) }
    , _optionsText { "OPTIONS", _context.fonts.get(FontHolder::ID::Arcade), 100 }
    , _startText { "START", _context.fonts.get(FontHolder::ID::Arcade), 100 }
    , _view { view }
{
	//set the position of the background sprite
	_backgroundSprite.setPosition(0, _view.getCenter().y - (_view.getSize().y/2));
	
	//setup the start button and associated rectangle
    _startText.setPosition(_view.getCenter().x - 425, _view.getCenter().y + 350);
    _startText.setFillColor(sf::Color::Black);
    
    _startRect.setSize(sf::Vector2f(_startText.getGlobalBounds().width + 10, _startText.getGlobalBounds().height + 10));
    _startRect.setPosition(_startText.getPosition() + sf::Vector2f(-3, 37));
    _startRect.setFillColor(sf::Color::Green);
    _startRect.setOutlineColor(sf::Color::Black);
    _startRect.setOutlineThickness(2);
    
    //setup the options button and associated rectangle
    _optionsText.setPosition(_view.getCenter().x + 75, _view.getCenter().y + 350);
    _optionsText.setFillColor(sf::Color::Black);
    
    _optionsRect.setSize(sf::Vector2f(_optionsText.getGlobalBounds().width + 10, _optionsText.getGlobalBounds().height + 10));
    _optionsRect.setPosition(_optionsText.getPosition() + sf::Vector2f(-3, 37));
    _optionsRect.setFillColor(sf::Color::Yellow);
    _optionsRect.setOutlineColor(sf::Color::Black);
    _optionsRect.setOutlineThickness(2);
    
}

//handle mouse input from the user
void MenuView::handleInput(std::vector<Command>& commandQueue){
	//check if the user is clicking within any of the keybinding rectangles
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		//get and map the mouse position
		sf::Vector2i pixelPos = sf::Mouse::getPosition(_context.window);
		sf::Vector2f worldPos = _context.window.mapPixelToCoords(pixelPos);
		
		//check the two rectangles
		if (_startRect.getGlobalBounds().contains(worldPos)){
			commandQueue.push_back(Command { Command::Type::Play });
		} else if (_optionsRect.getGlobalBounds().contains(worldPos)){
			commandQueue.push_back(Command { Command::Type::Options });
		}
		
	}
}

//update the screen
void MenuView::update(sf::Time dt, GameStateID state, const sf::FloatRect& worldBounds, std::vector<Command>& commandQueue)
{
	handleInput(commandQueue);
	//redraw all window elements
    sf::RenderWindow& window { _context.window };
	window.clear();
    window.draw(_backgroundSprite);
    window.draw(_startRect);
    window.draw(_optionsRect);
    window.draw(_startText);
    window.draw(_optionsText);
}

//dummy function
void MenuView::remapKeys(){}
