/**
 * @file Game.cpp
 * @author 
 * @brief Game class
 * @date 2021-03-24
 */

#include "Game.hpp"

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
    _viewList.emplace_back(std::make_unique<MenuView>(_context, _world));
    _viewList.emplace_back(std::make_unique<OptionsView>(_context, _world));
    _viewList.emplace_back(std::make_unique<AIView>(_sceneGraphLayers[static_cast<size_t>(SceneLayer::Enemies)], player_craft, _sceneGraphLayers[static_cast<size_t>(SceneLayer::Bullets)]));
}

void Game::changeState(GameStateID newState)
{
    _state = newState;
}

void Game::update(sf::Time dt)
{
    // a container to hold the commandQueue, processed differently based on the state
    std::vector<Command> commandQueue;
    std::vector<PendingChange> changeQueue;
    
    // state specifics
    switch (_state) {
    case GameStateID::Menu:
        _context.window.setView(_world);
    	//update the last view on the list, the options view
    	//no command queue processing is necessary, because the options view
    	//handles all input internally, since it requires such different i/o
    	_viewList.at(1)->update(dt, _state, getViewBounds(), commandQueue);
    	//display changes
    	_context.window.display();
    	//execute commands, these will only be state changes
    	for (auto& cmd : commandQueue){
    		switch (cmd.type){
    			case Command::Type::Options:
    				changeState(GameStateID::Options);
    				break;
    			case Command::Type::Play:
    				changeState(GameStateID::Play);
    				break;
    			default:
    				break;
    		}
    	}
        break;
        
    case GameStateID::Play:
    	//scroll the world view and update the screen accordingly
        _world.move(0.0f, _scrollSpeed * dt.asSeconds());
        _context.window.setView(_world);
        
        //update the player and AI views
		_viewList.front()->update(dt, _state, getViewBounds(), commandQueue);
		_viewList.back()->update(dt, _state, getViewBounds(), commandQueue);
    	_context.window.display();
    
    	//if the player is dead, go to game over
        if (player_craft->isDestroyed())
            changeState(GameStateID::Over);
        
        //complete game state specific commands
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
                		newNode = std::make_unique<Screamer>(_context);
                		break;
                	case EnemyType::Bogey:
                		newNode = std::make_unique<Bogey>(_context);
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

    	// Apply changes to the bullets onscreen
    	for (auto& change : changeQueue)
        	switch (change.type) {
        		case PendingChange::Type::AddBullet:
            			for (auto& newBullet : change.newBullets)
                		_sceneGraphLayers[static_cast<size_t>(SceneLayer::Bullets)]->attach(std::move(newBullet));
            			break;
        		default:
            			break;
        	}
		
		//adjust the velocities
    	_sceneGraphLayers[static_cast<size_t>(SceneLayer::Enemies)]->adaptVelocity();
    	_sceneGraphLayers[static_cast<size_t>(SceneLayer::Player)]->adaptVelocity();
		
		//detect collision, update the graph of everything onscreen, and cleanup
    	collisionDetection();
    	_sceneGraph.update(dt);
    	cleanUp();
    	
        break;
        
    case GameStateID::Pause:
        break;
    case GameStateID::Over:
        break;
    case GameStateID::Options:
    	//update the view in case of a resize event
    	_context.window.setView(_world);
    	//update the last view on the list, the options view
    	//no command queue processing is necessary, because the options view
    	//handles all input internally, since it requires such different i/o
    	_viewList.at(2)->update(dt, _state, getViewBounds(), commandQueue);
    	//display changes
    	_context.window.display();
    	//execute commands, these will only be state changes
    	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    		for (auto& cmd : commandQueue){
    			switch (cmd.type){
    				case Command::Type::Menu:
    					_viewList.front()->remapKeys();
    					changeState(GameStateID::Menu);
    					break;
    				default:
    					break;
    			}
    		}
    	}
    	break;
    default:
        break;
    }
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
    auto playerAircraft = std::make_unique<PlayerAircraft>(_scrollSpeed, _context);
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
