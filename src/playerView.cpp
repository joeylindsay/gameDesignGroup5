#include "PlayerView.hpp"
#include "SpriteNode.hpp"

PlayerView::PlayerView(Context& context, SceneNode& sceneGraph, sf::View& world, std::vector<sf::Event>& eventQueue, int maxHeight, PlayerAircraft*& playerAircraft)
    : GameView {}
    , _context { context }
    , _sceneGraph { sceneGraph }
    , _world { world }
    , _eventQueue { eventQueue }
    , _playerAircraft { playerAircraft }
    , _playerHealth { "", _context.fonts.get(FontHolder::ID::Arcade) }
{
    // Default Keymapping
    keyMapping[sf::Keyboard::W] = Command::Type::MoveUp;
    keyMapping[sf::Keyboard::A] = Command::Type::MoveLeft;
    keyMapping[sf::Keyboard::S] = Command::Type::MoveDown;
    keyMapping[sf::Keyboard::D] = Command::Type::MoveRight;
    keyMapping[sf::Keyboard::I] = Command::Type::TimeStop;
    keyMapping[sf::Keyboard::Space] = Command::Type::Fire;

    _playerHealth.setCharacterSize(30);
}

void PlayerView::update(sf::Time dt, GameStateID state, const sf::FloatRect& worldBounds, std::vector<Command>& commandQueue)
{
    processInput(commandQueue);
    render(dt, state);
}

void PlayerView::render(sf::Time dt, GameStateID state)
{
    _context.window.clear(sf::Color::Black);
    _context.window.draw(_sceneGraph);

    sf::Vector2f pos { _playerAircraft->getBoundingRect().left, _playerAircraft->getBoundingRect().top + 100.0f };
    _playerHealth.setString("HP: " + std::to_string(_playerAircraft->getHealth()));
    _playerHealth.setPosition(pos);
    _context.window.draw(_playerHealth);
}

void PlayerView::processInput(std::vector<Command>& commandQueue)
{
    // for (auto event : _eventQueue)
    //     if (event.type == sf::Event::KeyPressed && keyMapping.find(event.key.code) != keyMapping.end())
    //         commandQueue.emplace_back(keyMapping[event.key.code], _playerAircraft);
    
    // realtime input
    for (const auto& key_cmd : keyMapping)
        if (sf::Keyboard::isKeyPressed(key_cmd.first))
            // commandQueue.emplace_back(key_cmd.second, _playerAircraft);
            commandQueue.push_back(Command { key_cmd.second, _playerAircraft });
}
