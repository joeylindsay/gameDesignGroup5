#include "PlayerView.hpp"

PlayerView::PlayerView(Context& context, SceneNode& sceneGraph, sf::View& world, std::vector<sf::Event>& eventQueue, int maxHeight, PlayerAircraft*& playerAircraft)
    : GameView {}
    , _context { context }
    , _sceneGraph { sceneGraph }
    , _world { world }
    , _eventQueue { eventQueue }
    , _playerAircraft { playerAircraft }
    , _playerHealth { "", _context.fonts.get(FontHolder::ID::Arcade) }
    , _score { std::to_string(_context.score), _context.fonts.get(FontHolder::ID::Arcade), 55}
    , _stopIndicator { _context.textures.get(TextureHolder::ID::StopInactive) }
    , _pausedText { "Paused!  Press  Enter  to  Resume", _context.fonts.get(FontHolder::ID::Arcade), 50}
{
    //pause key is immutable
    keyMapping[sf::Keyboard::Escape] = Command::Type::Pause;
    
    //map the keys
    remapKeys();
    
   	//set the player size
    _playerHealth.setCharacterSize(30);
    
    //set the initial location of the score text
    _score.setPosition(_world.getCenter().x - 525, _world.getCenter().y - 550);
    
    // pause text
    _pausedText.setOrigin(_pausedText.getLocalBounds().width / 2.0f, _pausedText.getLocalBounds().height / 2.0f);
	_pausedText.setPosition(_world.getCenter().x, _world.getCenter().y);
    _pausedRect.setSize(sf::Vector2f(_world.getSize()));
    _pausedRect.setFillColor(sf::Color(0,0,0,150));
	_pausedRect.setPosition(_world.getCenter().x - 540, _world.getCenter().y - 540);
	
	//setup the position for the time stop indicator
	_stopIndicator.setPosition(world.getCenter().x + 450, _world.getCenter().y - 525);
}

void PlayerView::update(sf::Time dt, GameStateID state, const sf::FloatRect& worldBounds, std::vector<Command>& commandQueue)
{
    processInput(commandQueue);
    render(dt, state);
}

void PlayerView::render(sf::Time dt, GameStateID state)
{
	//draw all of the enemies and the player to the string
    _context.window.draw(_sceneGraph);

	//draw the player's health
    sf::Vector2f pos { _playerAircraft->getBoundingRect().left, _playerAircraft->getBoundingRect().top + 100.0f };
    _playerHealth.setString("HP " + std::to_string(_playerAircraft->getHealth()));
    _playerHealth.setPosition(pos);
    _context.window.draw(_playerHealth);
    
    //logic for pausing the game
    if (state == GameStateID::Pause) {
        _context.window.draw(_pausedRect);
        _context.window.draw(_pausedText);
    } else {
        _score.setString(std::to_string(_context.score));
        _score.move(0.0f, -50.0f * dt.asSeconds());
        _stopIndicator.move(0.0f, -50.0f * dt.asSeconds());
        _pausedText.move(0.0f, -50.0f * dt.asSeconds());
        _pausedRect.move(0.0f, -50.0f * dt.asSeconds());
    }
	
	//draw the score and time stop indicator
    _context.window.draw(_score);
    _context.window.draw(_stopIndicator);
}

void PlayerView::processInput(std::vector<Command>& commandQueue)
{
    // realtime input
    for (const auto& key_cmd : keyMapping)
        if (sf::Keyboard::isKeyPressed(key_cmd.first))
            commandQueue.push_back(Command { key_cmd.second, _playerAircraft });
}

//function to remap the keys after they're updated
void PlayerView::remapKeys(){
	//get the key strings
	rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * node;
    rapidxml::file<> xmlFile("../data/options.xml");

	//parse the xml file and setup a node at the first keybinding
    doc.parse<0>(xmlFile.data());
    node = doc.first_node("options");
    node = node->first_node("key");
    
    //read in all of the keybindings
    std::string up = node->value();
    node = node->next_sibling();
    std::string down = node->value();
    node = node->next_sibling();
    std::string left = node->value();
    node = node->next_sibling();
    std::string right = node->value();
    node = node->next_sibling();
    std::string shoot = node->value();
    node = node->next_sibling();
    std::string timeStop = node->value();
    
    //apply all of the keymappings
	keyMapping[_context.keyMap.stringToKey(up)] = Command::Type::MoveUp;
    keyMapping[_context.keyMap.stringToKey(left)] = Command::Type::MoveLeft;
    keyMapping[_context.keyMap.stringToKey(down)] = Command::Type::MoveDown;
    keyMapping[_context.keyMap.stringToKey(right)] = Command::Type::MoveRight;
    keyMapping[_context.keyMap.stringToKey(shoot)] = Command::Type::Fire;
    keyMapping[_context.keyMap.stringToKey(timeStop)] = Command::Type::TimeStop;
}

//change the texture of the time stop indicator
void PlayerView::stopIndic(bool b){
	if (b){
		_stopIndicator.setTexture(_context.textures.get(TextureHolder::ID::StopActive));
	} else {
		_stopIndicator.setTexture(_context.textures.get(TextureHolder::ID::StopInactive));
	}
}
