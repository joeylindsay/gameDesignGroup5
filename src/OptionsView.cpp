//the main file for the options screen
#include <OptionsView.hpp>

using namespace rapidxml;
using namespace std;

OptionsView::OptionsView(Context& context, sf::View& world)
	//setup the local information
    : GameView {}
    , _context { context }
    , _view { world }
    , _up_button { "", _context.fonts.get(FontHolder::ID::Arial), 24}
    , _down_button { "", _context.fonts.get(FontHolder::ID::Arial), 24}
    , _left_button { "", _context.fonts.get(FontHolder::ID::Arial), 24}
    , _right_button { "", _context.fonts.get(FontHolder::ID::Arial), 24}
    , _shoot_button { "", _context.fonts.get(FontHolder::ID::Arial), 24}
    , _optionsSprite { _context.textures.get(TextureHolder::ID::Cockpit) }
    
{
	//read in the xml file
    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * node;
    rapidxml::file<> xmlFile("../data/options.xml");

	//parse the xml file and setup a node at the first keybinding
    doc.parse<0>(xmlFile.data());
    node = doc.first_node("options");
    node = node->first_node("key");
    
    //read in all of the keybindings
    _stringVec.push_back(node->value());
    
    node = node->next_sibling();
    _stringVec.push_back(node->value());
    
    node = node->next_sibling();
    _stringVec.push_back(node->value());
    
    node = node->next_sibling();
    _stringVec.push_back(node->value());
    
    node = node->next_sibling();
    _stringVec.push_back(node->value());
    
    //set the positions of the options onscreen
    _up_button.setPosition(_view.getCenter().x - 200, _view.getCenter().y);
    _down_button.setPosition(_view.getCenter().x - 200, _view.getCenter().y + 75);
    _left_button.setPosition(_view.getCenter().x + 75, _view.getCenter().y);
    _right_button.setPosition(_view.getCenter().x + 75, _view.getCenter().y + 75);
    _shoot_button.setPosition(_view.getCenter().x - 65, _view.getCenter().y + 150);
    _optionsSprite.setPosition(0, _view.getCenter().y - (_view.getSize().y/2));
    
    //cleanup memory
    doc.clear();
    
	//load in all of the rectangles and setup final text strings
    reloadText();
}

//handle input from the user to allow them to change keybindings
void OptionsView::handleInput(std::vector<Command>& commandQueue) {
	
	//check if the user is clicking within any of the keybinding rectangles
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		//get and map the mouse position
		sf::Vector2i pixelPos = sf::Mouse::getPosition(_context.window);
		sf::Vector2f worldPos = _context.window.mapPixelToCoords(pixelPos);

		//check to see if the user clicked inside of one of the keybinding rectangles
		for (auto& rect : recVec){
			if (rect.second.getGlobalBounds().contains(worldPos)){
				//if they did, check every SFML key until they press one {NOTE: I would have liked to have done this with events,
				//but we're already popping the event queue in the application layer, so this looping ridiculousness was the only way}
				bool loop = true;
				
				while (loop){
					for (int keyCode = 0; keyCode <= sf::Keyboard::KeyCount; keyCode++){
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyCode))){
							std::string tmpStr = _context.keyMap.keyToString(sf::Keyboard::Key(keyCode));
							if (tmpStr.compare("Unknown")){
								_stringVec.at(rect.first) = _context.keyMap.keyToString(sf::Keyboard::Key(keyCode));
								writeFile();
								reloadText();
							} 
							loop = false;
							break;
						}
					}
				}
				break;
			}
		}
	}
}

//write the new keybindings to the xml file
void OptionsView::writeFile(){
	//read in the xml file
    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * node;
    rapidxml::xml_node<> * rootNode;
    rapidxml::xml_node<> * newNode;
    rapidxml::file<> xmlFile("../data/options.xml");

	//parse the xml file and setup a node at the first keybinding
    doc.parse<0>(xmlFile.data());
    rootNode = doc.first_node("options");
    node = rootNode->first_node("key");
    
    //step along the nodes and write out the values
    for (auto& stringKey : _stringVec){
    	node->value(stringKey.data());
    	newNode = doc.allocate_node( rapidxml::node_element, node->name(), node->value() );
    	rootNode->append_node( newNode );
    	node = node->next_sibling();
    	rootNode->remove_first_node();
    }
    
    //write the changes
    std::ofstream out("../data/options.xml");
    out << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << std::endl;
    out << doc;
    out.close();
    doc.clear();
}

//redraw all of the onscreen elements
void OptionsView::reloadText(){
	//set the text of the options onscreen
    _up_button.setString("Forward: " + _stringVec.at(0));
    _down_button.setString("Backward: " + _stringVec.at(1));
    _left_button.setString("Left: " + _stringVec.at(2));
    _right_button.setString("Right: " + _stringVec.at(3));
    _shoot_button.setString("Fire: " + _stringVec.at(4));
    
    //setup the onscreen rectangles
    _upRect.setSize(sf::Vector2f(_up_button.getGlobalBounds().width + 10, _up_button.getGlobalBounds().height + 10));
    _upRect.setPosition(_up_button.getPosition() + sf::Vector2f(-3, 3));
    _upRect.setFillColor(sf::Color::Blue);
    _upRect.setOutlineColor(sf::Color::Cyan);
    _upRect.setOutlineThickness(2);
    
    _downRect.setSize(sf::Vector2f(_down_button.getGlobalBounds().width + 10, _down_button.getGlobalBounds().height + 10));
    _downRect.setPosition(_down_button.getPosition() + sf::Vector2f(-3, 3));
    _downRect.setFillColor(sf::Color::Blue);
    _downRect.setOutlineColor(sf::Color::Cyan);
    _downRect.setOutlineThickness(2);
    
    _leftRect.setSize(sf::Vector2f(_left_button.getGlobalBounds().width + 10, _left_button.getGlobalBounds().height + 10));
    _leftRect.setPosition(_left_button.getPosition() + sf::Vector2f(-3, 3));
    _leftRect.setFillColor(sf::Color::Blue);
    _leftRect.setOutlineColor(sf::Color::Cyan);
    _leftRect.setOutlineThickness(2);
    
    _rightRect.setSize(sf::Vector2f(_right_button.getGlobalBounds().width + 10, _right_button.getGlobalBounds().height + 10));
    _rightRect.setPosition(_right_button.getPosition() + sf::Vector2f(-3, 3));
    _rightRect.setFillColor(sf::Color::Blue);
    _rightRect.setOutlineColor(sf::Color::Cyan);
    _rightRect.setOutlineThickness(2);
    
    _shootRect.setSize(sf::Vector2f(_shoot_button.getGlobalBounds().width + 10, _shoot_button.getGlobalBounds().height + 10));
    _shootRect.setPosition(_shoot_button.getPosition() + sf::Vector2f(-3, 3));
    _shootRect.setFillColor(sf::Color::Blue);
    _shootRect.setOutlineColor(sf::Color::Cyan);
    _shootRect.setOutlineThickness(2);
    
    //push the rectangles onto a vector
    recVec.clear();
    recVec[0] = _upRect;
    recVec[1] = _downRect;
    recVec[2] = _leftRect;
    recVec[3] = _rightRect;
    recVec[4] = _shootRect;
}

//update all of the onscreen elements and process input
void OptionsView::update(sf::Time dt, GameStateID state, const sf::FloatRect& worldBounds, std::vector<Command>& commandQueue){
	sf::RenderWindow& window { _context.window };	
	
	handleInput(commandQueue);
	//redraw everything onscreen
	_context.window.draw(_optionsSprite);
	_context.window.draw(_upRect);
	_context.window.draw(_downRect);
	_context.window.draw(_leftRect);
	_context.window.draw(_rightRect);
	_context.window.draw(_shootRect);
	_context.window.draw(_shootRect);
	_context.window.draw(_up_button);
    _context.window.draw(_down_button);
    _context.window.draw(_left_button);
    _context.window.draw(_right_button);
    _context.window.draw(_shoot_button);   	
}
