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
{
    //pause key is immutable
    keyMapping[sf::Keyboard::Escape] = Command::Type::Pause;
    
    //map the keys
    remapKeys();
    
   	//set the player size
    _playerHealth.setCharacterSize(30);
    
    //set the initial location of the score text
    _score.setPosition(_world.getCenter().x - 525, _world.getCenter().y - 550);
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
    _playerHealth.setString("HP: " + std::to_string(_playerAircraft->getHealth()));
    _playerHealth.setPosition(pos);
    _context.window.draw(_playerHealth);
    
    //draw the score
    _score.setString(std::to_string(_context.score));
    _score.move(0.0f, -50.0f * dt.asSeconds());
    _context.window.draw(_score);
}

void PlayerView::processInput(std::vector<Command>& commandQueue)
{
    // realtime input
    for (const auto& key_cmd : keyMapping)
        if (sf::Keyboard::isKeyPressed(key_cmd.first))
            // commandQueue.emplace_back(key_cmd.second, _playerAircraft);
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
    const std::string timeStop = node->value();
    
    //apply all of the keymappings
	keyMapping[_context.keyMap.stringToKey(up)] = Command::Type::MoveUp;
    keyMapping[_context.keyMap.stringToKey(left)] = Command::Type::MoveLeft;
    keyMapping[_context.keyMap.stringToKey(down)] = Command::Type::MoveDown;
    keyMapping[_context.keyMap.stringToKey(right)] = Command::Type::MoveRight;
    keyMapping[_context.keyMap.stringToKey(timeStop)] = Command::Type::TimeStop;
    keyMapping[_context.keyMap.stringToKey(shoot)] = Command::Type::Fire;
}
