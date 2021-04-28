/**
 * @file Game.cpp
 * @author 
 * @brief Game class
 * @date 2021-03-24
 */

#include "Game.hpp"
#include "AIView.hpp"
#include "Context.hpp"
#include "EnemyType.hpp"
#include "MenuView.hpp"
#include "PendingChange.hpp"
#include "PlayerAircraft.hpp"
#include "PlayerView.hpp"
#include "SceneNode.hpp"
#include "Screamer.hpp"
#include "SpriteNode.hpp"
#include <SFML/Graphics.hpp>
#include <queue>

Game::Game(Context& context, std::vector<sf::Event>& eventQueue)
    : _context { context }
    , _eventQueue { eventQueue }
    , _sceneGraphLayers(static_cast<size_t>(SceneLayer::LayerCount))
    , _world { sf::Vector2f(0.0f,0.0f), sf::Vector2f(_worldSize.x, _worldSize.y) }
    , _spawnPosition { _world.getSize().x / 2.0f, _maxHeight - _world.getSize().y / 2.0f }
{
    _world.setCenter(_spawnPosition);

    buildScene();

    // Register views
    _viewList.emplace_back(std::make_unique<PlayerView>(_context, _sceneGraph, _world, eventQueue, _maxHeight, player_craft));
    _viewList.emplace_back(std::make_unique<MenuView>(_context));
    _viewList.emplace_back(std::make_unique<AIView>(_sceneGraphLayers[static_cast<size_t>(SceneLayer::Enemies)], player_craft, _sceneGraphLayers[static_cast<size_t>(SceneLayer::Bullets)]));
}

void Game::changeState(GameStateID newState)
{
    _state = newState;
}

void Game::update(sf::Time dt)
{
    // state specifics
    switch (_state) {
    case GameStateID::Menu:
        for (auto event : _eventQueue)
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                changeState(GameStateID::Play);
                break;
            }
        break;
    case GameStateID::Play:
        _world.move(0.0f, -50.0f * dt.asSeconds());
        _context.window.setView(_world);

        if (player_craft->isDestroyed())
            changeState(GameStateID::Over);
        break;
    case GameStateID::Pause:
        break;
    case GameStateID::Over:
        break;
    default:
        break;
    }

    // update all views
    std::vector<Command> commandQueue;
    for (auto& view : _viewList)
        view->update(dt, _state, getViewBounds(), commandQueue);
    _context.window.display();
    
    // complete requested commands
    std::vector<PendingChange> changeQueue;
    _sceneGraphLayers[static_cast<size_t>(SceneLayer::Enemies)]->resetVelocity();
    _sceneGraphLayers[static_cast<size_t>(SceneLayer::Player)]->resetVelocity();
    for (auto& cmd : commandQueue)
        switch (cmd.type) {
        case Command::Type::MoveLeft:
            cmd.entity->setUnitVelocity(-1, 0);
            break;
        case Command::Type::MoveRight:
            cmd.entity->setUnitVelocity(1, 0);
            break;
        case Command::Type::MoveUp:
            cmd.entity->setUnitVelocity(0, -1);
            break;
        case Command::Type::MoveDown:
            cmd.entity->setUnitVelocity(0, 1);
            break;
        case Command::Type::Fire:
            static_cast<Aircraft*>(cmd.entity)->fire(changeQueue);
            break;
        case Command::Type::AddEnemy: {
            std::unique_ptr<SceneNode> newNode;
            switch (cmd.newEnemyType) {
            case EnemyType::Screamer:
                newNode = std::make_unique<Screamer>(_context.textures);
                break;
            default:
                break;
            }
            newNode->setPosition(cmd.position);
            _sceneGraphLayers[static_cast<size_t>(SceneLayer::Enemies)]->attach(std::move(newNode));
        } break;

        default:
            break;
        }

    // Apply pending changes
    for (auto& change : changeQueue)
        switch (change.type) {
        case PendingChange::Type::AddBullet:
            for (auto& newBullet : change.newBullets)
                _sceneGraphLayers[static_cast<size_t>(SceneLayer::Bullets)]->attach(std::move(newBullet));
            break;

        default:
            break;
        }

    _sceneGraphLayers[static_cast<size_t>(SceneLayer::Enemies)]->adaptVelocity();
    _sceneGraphLayers[static_cast<size_t>(SceneLayer::Player)]->adaptVelocity();

    collisionDetection();
    _sceneGraph.update(dt);
    cleanUp();
}

void Game::buildScene()
{
    // Attatch the subroots for the layers
    for (auto& layer : _sceneGraphLayers) {
        auto node { std::make_unique<SceneNode>() };
        layer = node.get();
        _sceneGraph.attach(std::move(node));
    }

    // Attatch background
    sf::Texture& jungleBackground = _context.textures.get(TextureHolder::ID::JungleBackground);
    jungleBackground.setRepeated(true);
    auto background { std::make_unique<SpriteNode>(jungleBackground, sf::IntRect { 0, 0, _worldSize.x, _maxHeight + _worldSize.y }) };
    background->setPosition(sf::Vector2f { 0.0f, -static_cast<float>(_worldSize.y) });
    _sceneGraphLayers[static_cast<size_t>(SceneLayer::Background)]->attach(std::move(background));

    // Attach player
    auto playerAircraft = std::make_unique<PlayerAircraft>(_context.textures, _scrollSpeed);
    playerAircraft->setPosition(_spawnPosition);
    player_craft = playerAircraft.get();
    _sceneGraphLayers[static_cast<size_t>(SceneLayer::Player)]->attach(std::move(playerAircraft));
    
    //resize the window the to appropriate size
    resize();
}

void Game::cleanUp()
{
    _sceneGraphLayers[static_cast<size_t>(SceneLayer::Enemies)]->cleanUp(getWorldBounds());
    _sceneGraphLayers[static_cast<size_t>(SceneLayer::Bullets)]->cleanUp(getWorldBounds());
}

sf::FloatRect Game::getViewBounds() const
{
    return sf::FloatRect { _world.getCenter() - _world.getSize() / 2.0f, _world.getSize() };
}

sf::FloatRect Game::getWorldBounds() const
{
    sf::FloatRect view { getViewBounds() };
    view.top -= 100.0f;
    view.height += 100.0f;
    return view;
}

void Game::collisionDetection()
{
    // between bullet and others
    for (auto& bullet : _sceneGraphLayers[static_cast<size_t>(SceneLayer::Bullets)]->getChildren()) {
        // player bullet. check for enemies.
        if (bullet->getVelocity().y < 0) {
            for (auto& enemy : _sceneGraphLayers[static_cast<size_t>(SceneLayer::Enemies)]->getChildren())
                if (enemy->checkCollision(bullet->getBoundingRect(), bullet->getDamageValue())) {
                    bullet->destroy();
                }
        } else { // bullet from enemy. check for player
            if (player_craft->checkCollision(bullet->getBoundingRect(), bullet->getDamageValue())) {
                bullet->destroy();
            }
        }
    }
}

void Game::resize(){
	float xSize = _context.window.getSize().x;
	float ySize = _context.window.getSize().y;
	
	//if the x width is bigger, scale to y
	if (xSize > ySize){
		float scalefactor = ySize / xSize;
		_world.setViewport(sf::FloatRect((1.0f - scalefactor)/2.0f, 0.0f, scalefactor, 1.0f));
		
	}else{	//if the y width is bigger, scale to x
		float scalefactor = xSize / ySize;
		_world.setViewport(sf::FloatRect(0.0f, (1.0f - scalefactor)/2.0f, 1.0f, scalefactor));
	}
	//clear the window
	_context.window.clear(sf::Color::Black);
}
