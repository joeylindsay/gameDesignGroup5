/**
 * @file Game.hpp
 * @author Rui Hou, Harrison Keen, Joey Lindsay, Kathy Ngo 
 * @brief Header file for Game class
 * @date 2021-03-24
 */

#pragma once

#include "Context.hpp"
#include "Command.hpp"
#include "GameStateID.hpp"
#include "GameView.hpp"
#include "SceneNode.hpp"
#include "AIView.hpp"
#include "EnemyType.hpp"
#include "MenuView.hpp"
#include "PendingChange.hpp"
#include "PlayerAircraft.hpp"
#include "PlayerView.hpp"
#include "OptionsView.hpp"
#include "SceneNode.hpp"
#include "Screamer.hpp"
#include "Bogey.hpp"
#include "SpriteNode.hpp"
#include <SFML/Graphics.hpp>
#include <queue>
#include <vector>
#include <iostream>

/**
 * @brief Implements the actual Interceptors game.
 */
class Game {
public:
    enum class SceneLayer {
        Background,
        Bullets,
        Enemies,
        Player,
        LayerCount
    };
    Game(Context& context, std::vector<sf::Event>& eventQueue);
    /// Logical update
    /// \param dt Time of current frame
    void update(sf::Time dt);
    void changeState(GameStateID newState);
    void resize();

private:
    void buildScene();
    void cleanUp();
    sf::FloatRect getViewBounds() const;
    sf::FloatRect getWorldBounds() const;
    void collisionDetection();
    GameStateID _state { GameStateID::Menu };
    std::vector<std::unique_ptr<GameView>> _viewList;
    Context& _context;
    SceneNode _sceneGraph { };
    std::vector<SceneNode*> _sceneGraphLayers;
    sf::Vector2i _worldSize { 1080, 1080 };
    int _maxHeight { 50000 };
    std::vector<sf::Event>& _eventQueue;
    PlayerAircraft* player_craft;
    float _scrollSpeed = -50.0f;
    sf::View _world;
    sf::Vector2f _spawnPosition;
};
