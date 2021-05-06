/// \file AIView.hpp
/// \author Rui Hou, Joey Lindsay, Harrison Keen, Kathy Ngo
/// \brief Header file for the AIView class
/// \date 2021-04-02

#pragma once

#include "GameView.hpp"
#include "EnemyType.hpp"
#include "SceneNode.hpp"
#include "PlayerAircraft.hpp"
#include <stdlib.h>
#include "Command.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

/// AI's view on the game. Use AI's strategyes to control the enemys.
class AIView : public GameView
{
public:
    AIView(SceneNode*& enemies, PlayerAircraft*& player, SceneNode*& bullets);
    void update(sf::Time dt, GameStateID state, const sf::FloatRect& worldBounds, std::vector<Command>& commandQueue) override;
    //dummy functions
    void remapKeys() override;
    void stopIndic(bool b) override;
private:
    struct SpawnSchedule {
        EnemyType type;
        sf::Vector2f position;
    };
    void updateEnemy(SceneNode* cur, std::vector<Command>& commandQueue);
    /// schedule on when to place which enemy into the game world. Should be sorted in descending order in y.
    std::vector<SpawnSchedule> _schedule;
    /// iterator pointing to the next enemy to spawn in the schedule. 
    std::vector<SpawnSchedule>::iterator _nextToSpawn;
    SceneNode*& _enemies;
    SceneNode*& _bullets;
    PlayerAircraft*& _player;
    //for when the player reaches the end of the level
    int randPos = -1;
    sf::Time endTimes { sf::Time::Zero };
};
