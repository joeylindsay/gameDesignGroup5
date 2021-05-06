/// \file AIView.cpp
/// \author Rui Hou, Joey Lindsay, Harrison Keen, Kathy Ngo
/// \brief Source file for the AIView class
/// \date 2021-04-02
#include "AIView.hpp"

AIView::AIView(SceneNode*& enemies, PlayerAircraft*& player, SceneNode*& bullets)
    : GameView {}
    , _enemies { enemies }
    , _bullets { bullets }
    , _player { player }
{
    _schedule = std::vector<SpawnSchedule> {
    	//first two enemies to get the player adjusted
        { EnemyType::Bogey,    { 540.0f, 48500.0f }},
        { EnemyType::Screamer, { 540.0f, 48000.0f }},
        
        //both onscreen at once
        /*{ EnemyType::Bogey,    { 660.0f, 47500.0f }},
        { EnemyType::Screamer, { 480.0f, 47500.0f }},
        
        { EnemyType::Bogey,    { 200.0f, 47000.0f }},
        { EnemyType::Bogey,    { 700.0f, 47000.0f }},
        { EnemyType::Screamer, { 480.0f, 47000.0f }},
        
        { EnemyType::Screamer, { 75.0f,  46500.0f }},
        { EnemyType::Bogey,    { 480.0f, 46500.0f }},
        { EnemyType::Screamer, { 700.0f, 46500.0f }},
        
        { EnemyType::Screamer, { 75.0f,  46000.0f }},
        { EnemyType::Bogey,    { 400.0f, 46000.0f }},
        { EnemyType::Bogey,    { 550.0f, 46000.0f }},
        { EnemyType::Screamer, { 700.0f, 46000.0f }},
        
        { EnemyType::Bogey,    { 75.0f,  45500.0f }},
        { EnemyType::Screamer, { 400.0f, 45500.0f }},
        { EnemyType::Screamer, { 550.0f, 45500.0f }},
        { EnemyType::Bogey,    { 700.0f, 45500.0f }},
        
        { EnemyType::Screamer, { 250.0f, 45000.0f }},
        { EnemyType::Screamer, { 400.0f, 45000.0f }},
        { EnemyType::Screamer, { 550.0f, 45000.0f }},
        { EnemyType::Screamer, { 700.0f, 45000.0f }},
        
        { EnemyType::Bogey,    { 250.0f, 44500.0f }},
        { EnemyType::Bogey,    { 400.0f, 44500.0f }},
        { EnemyType::Bogey,    { 550.0f, 44500.0f }},
        { EnemyType::Bogey,    { 700.0f, 44500.0f }},
        
        { EnemyType::Screamer, { 75.0f,  44000.0f }},
        { EnemyType::Bogey,    { 350.0f, 44000.0f }},
        { EnemyType::Bogey,    { 500.0f, 44000.0f }},
        { EnemyType::Bogey,    { 650.0f, 44000.0f }},
        { EnemyType::Screamer, { 900.0f, 44000.0f }},
        
        { EnemyType::Screamer, { 75.0f,  43500.0f }},
        { EnemyType::Screamer, { 900.0f, 43400.0f }},
        { EnemyType::Screamer, { 350.0f, 43300.0f }},
        { EnemyType::Screamer, { 200.0f, 43200.0f }},
        { EnemyType::Screamer, { 100.0f, 43100.0f }},
        { EnemyType::Screamer, { 650.0f, 43000.0f }},
        
        { EnemyType::Screamer, { 75.0f,  42500.0f }},
        { EnemyType::Screamer, { 900.0f, 42450.0f }},
        { EnemyType::Screamer, { 350.0f, 42400.0f }},
        { EnemyType::Screamer, { 200.0f, 42350.0f }},
        { EnemyType::Screamer, { 100.0f, 42300.0f }},
        { EnemyType::Screamer, { 650.0f, 42250.0f }},
        { EnemyType::Screamer, { 700.0f, 42200.0f }},
        { EnemyType::Screamer, { 325.0f, 42150.0f }},
        { EnemyType::Screamer, { 950.0f, 42100.0f }},
        { EnemyType::Screamer, { 100.0f, 42050.0f }},
        { EnemyType::Screamer, { 480.0f, 42000.0f }},
        
        { EnemyType::Bogey,    { 200.0f, 41500.0f }},
        { EnemyType::Screamer, { 950.0f, 41400.0f }},
        { EnemyType::Bogey,    { 400.0f, 41300.0f }},
        { EnemyType::Screamer, { 100.0f, 41200.0f }},
        { EnemyType::Bogey,    { 600.0f, 41100.0f }},
		{ EnemyType::Screamer, { 500.0f, 41000.0f }},
		
		{ EnemyType::Screamer, { 75.0f,  40500.0f }},
        { EnemyType::Bogey,    { 900.0f, 40450.0f }},
        { EnemyType::Screamer, { 350.0f, 40400.0f }},
        { EnemyType::Bogey,    { 200.0f, 40350.0f }},
        { EnemyType::Screamer, { 100.0f, 40300.0f }},
        { EnemyType::Bogey,    { 650.0f, 40250.0f }},
        { EnemyType::Screamer, { 700.0f, 40200.0f }},
        { EnemyType::Bogey,    { 325.0f, 40150.0f }},
        { EnemyType::Screamer, { 950.0f, 40100.0f }},
        { EnemyType::Bogey,    { 100.0f, 40050.0f }},
        { EnemyType::Screamer, { 480.0f, 40000.0f }},
        
        { EnemyType::Bogey,    { 75.0f,  39500.0f }},
        { EnemyType::Bogey,    { 150.0f, 39500.0f }},
        { EnemyType::Bogey,    { 225.0f, 39500.0f }},
        { EnemyType::Bogey,    { 300.0f, 39500.0f }},
        { EnemyType::Bogey,    { 375.0f, 39500.0f }},
        { EnemyType::Bogey,    { 450.0f, 39500.0f }},
        { EnemyType::Bogey,    { 750.0f, 39500.0f }},
        { EnemyType::Bogey,    { 825.0f, 39500.0f }},
        { EnemyType::Bogey,    { 900.0f, 39500.0f }},
        { EnemyType::Bogey,    { 975.0f, 39500.0f }},
        { EnemyType::Bogey,    { 1050.0f, 39500.0f }},
        
        { EnemyType::Flagship, { 480.0f, 39000.0f }},*/
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
    
    //randomly generate the level after the player has finished the main level
    if(worldBounds.top < 48900.0f && endTimes >= sf::seconds(1.0f)) {
    	endTimes = sf::Time::Zero;
    	randPos = rand() % 40;
    	if (randPos > 20){
    		commandQueue.emplace_back(Command::Type::AddEnemy, nullptr);
    		if (randPos >= 20 && randPos < 30){
    			commandQueue.back().newEnemyType = EnemyType::Screamer;
    		} else if (randPos >= 30 && randPos < 40 ){
    			commandQueue.back().newEnemyType = EnemyType::Bogey;
    		} else if (randPos == 40){
				commandQueue.back().newEnemyType = EnemyType::Flagship;
    		}
        	commandQueue.back().position = sf::Vector2f((float)(rand() % 900 + 75), worldBounds.top - 100.0f);
        }
    
    }
    endTimes+=dt;
    
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

//dummy functions
void AIView::remapKeys(){}
void AIView::stopIndic(bool b){}
