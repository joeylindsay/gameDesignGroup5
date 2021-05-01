/// \file AIView.cpp
/// \author Rui Hou, Joey Lindsay, Harrison Keen, Kathy Ngo
/// \brief Source file for the AIView class
/// \date 2021-04-02
#include "AIView.hpp"
#include "PlayerAircraft.hpp"
#include "SceneNode.hpp"
#include "Screamer.hpp"
#include <SFML/Graphics.hpp>

AIView::AIView(SceneNode*& enemies, PlayerAircraft*& player, SceneNode*& bullets)
    : GameView {}
    , _enemies { enemies }
    , _bullets { bullets }
    , _player { player }
{   

    _schedule = std::vector<SpawnSchedule> {
        { EnemyType::Screamer, { 300.0f, 48900.0f }},
        { EnemyType::Bogey,    { 600.0f, 48800.0f }},
        { EnemyType::Screamer, { 200.0f, 48600.0f }},
        { EnemyType::Screamer, { 700.0f, 48600.0f }},
        { EnemyType::Bogey,    { 400.0f, 48500.0f }},
    };
    _nextToSpawn = _schedule.begin();
}

void AIView::update(sf::Time dt, GameStateID state, const sf::FloatRect& worldBounds, std::vector<Command>& commandQueue)
{
    while (_nextToSpawn != _schedule.end() && _nextToSpawn->position.y > worldBounds.top - 100.0f) {
        commandQueue.emplace_back(Command::Type::AddEnemy, nullptr);
        commandQueue.back().newEnemyType = _nextToSpawn->type;
        commandQueue.back().position = _nextToSpawn->position;
        ++_nextToSpawn;
    }
    for (auto& child : _enemies->_children)
        updateEnemy(child.get(), commandQueue);
}

void AIView::updateEnemy(SceneNode* cur, std::vector<Command>& commandQueue)
{
    commandQueue.emplace_back(Command::Type::Fire, cur);

    Aircraft* cur_aircraft = dynamic_cast<Aircraft*>(cur);
    const sf::Vector2i& nextStep = cur_aircraft->getNextStep();
    
    if (nextStep.x == 1)
        commandQueue.emplace_back(Command::Type::MoveRight, cur);
    else if (nextStep.x == -1)
        commandQueue.emplace_back(Command::Type::MoveLeft, cur);

    if (nextStep.y == 1)
        commandQueue.emplace_back(Command::Type::MoveDown, cur);
    else if (nextStep.y == -1)
        commandQueue.emplace_back(Command::Type::MoveUp, cur);
    
}
