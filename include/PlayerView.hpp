#pragma once

#include "Context.hpp"
#include "Command.hpp"
#include "Game.hpp"
#include "GameStateID.hpp"
#include "GameView.hpp"
#include "PlayerAircraft.hpp"
#include "SceneNode.hpp"
#include "SpriteNode.hpp"
#include <SFML/Graphics.hpp>
#include <map>
#include "../RapidXML/rapidxml_ext.hpp"

class PlayerView : public GameView
{
public:
    PlayerView(Context& context, SceneNode& sceneGraph, sf::View& world, std::vector<sf::Event>& eventQueue, int maxHeight, PlayerAircraft*& playerAircraft);
    void update(sf::Time dt, GameStateID state, const sf::FloatRect& worldBounds, std::vector<Command>& commandQueue) override;
    void remapKeys() override;

private:
    void render(sf::Time dt, GameStateID state);
    void processInput(std::vector<Command>& commandQueue);
    sf::View _world;
    SceneNode& _sceneGraph;
    std::vector<sf::Event>& _eventQueue;
    std::map<sf::Keyboard::Key, Command::Type> keyMapping;
    PlayerAircraft*& _playerAircraft;
    Context& _context;
    sf::Text _playerHealth;
    sf::Text _score;
};
