//the main file for the options screen

#include <iostream>
#include <fstream>
#include <vector>
#include "../RapidXML/rapidxml.hpp"
#include "../RapidXML/rapidxml_print.hpp"
#include <options.hpp>

using namespace rapidxml;
using namespace std;

interceptors::options::options() {
	using interceptors::options;
	//TODO
    volume = 20;
    m_scale = 1;
    m_winsizeX = 800;
    m_winsizeY = 600;

    sf::Texture option;
    option.loadFromFile("../assets/interceptorsprite.png");
    optionsSprite.setTexture(option);

    rapidxml::xml_document<> doc;
    xml_node<> * root_node;
    ifstream file("options.xml");
    vector<char> buffer((istreambuf_iterator<char>(file)), istreambuf_iterator<char>( ));
    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);
    root_node = doc.first_node("options");
    moveup = root_node->first_attribute("moveup")->value();
    movedown = root_node->first_attribute("movedown")->value();
    moveleft = root_node->first_attribute("moveleft")->value();
    moveright = root_node->first_attribute("moveright")->value();
    shoot = root_node->first_attribute("shoot")->value();
    volumeup = root_node->first_attribute("volumeup")->value();
    volumedown = root_node->first_attribute("volumedown")->value();

}

void interceptors::options::handleInput(sf::Event event) {
    using interceptors::options;
    if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Add) {
            if (volume + 1 != 100) {
                volume++;
            }
        }
        else if (event.key.code == sf::Keyboard::Subtract) {
            if (volume - 1 != 0) {
                volume--;
            }
        }
        else if (event.key.code == sf::Keyboard::Num1) {
            moveup = "Up";
            movedown = "Down";
            moveleft = "Left";
            moveright = "Right";
        }
        else if (event.key.code == sf::Keyboard::Num2) {
            moveup = "W";
            movedown = "S";
            moveleft = "A";
            moveright = "D";
        }
    }

    rapidxml::xml_document<> doc;
    xml_node<> * root_node;
    ifstream file("options.xml");
    vector<char> buffer((istreambuf_iterator<char>(file)), istreambuf_iterator<char>( ));
    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);
    root_node = doc.first_node("options");
    std::string new_moveup = moveup.data();
    root_node->first_attribute("moveup")->value(new_moveup.data());
    std::string new_movedown = movedown.data();
    root_node->first_attribute("movedown")->value(new_movedown.data());
    std::string new_moveleft = moveleft.data();
    root_node->first_attribute("moveleft")->value(new_moveleft.data());
    std::string new_moveright = moveright.data();
    root_node->first_attribute("moveright")->value(new_moveright.data());
    std::string new_shoot = shoot.data();
    root_node->first_attribute("shoot")->value(new_shoot.data());
    std::string new_volumeup = volumeup.data();
    root_node->first_attribute("volumeup")->value(new_volumeup.data());
    std::string new_volumedown = volumedown.data();
    root_node->first_attribute("volumedown")->value(new_volumedown.data());

    std::ofstream file_stored("options.xml");
    file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << std::endl;
    file_stored << doc;
    file_stored.close();
    doc.clear();
}


void interceptors::options::show(sf::RenderWindow& window) {
	using interceptors::options;
	//TODO
	sf::Text up_button;
    sf::Text down_button;
    sf::Text left_button;
    sf::Text right_button;
    sf::Text shoot_button;
    sf::Text volume_level;

    sf::Font style;
    if (!style.loadFromFile("../assets/Arial.ttf")) {
        std::cout << "Font not located." << std::endl;
    }

    up_button.setString("The button to move the player forward is: " + moveup);
    up_button.setCharacterSize(24);
    up_button.setFont(style);
    up_button.setColor(sf::Color::Red);
    up_button.setPosition(200, 300);

    down_button.setString("The button to move the player backward is: " + movedown);
    down_button.setCharacterSize(24);
    down_button.setFont(style);
    down_button.setColor(sf::Color::Red);
    down_button.setPosition(200, 330);

    left_button.setString("The button to move the player left is: " + moveleft);
    left_button.setCharacterSize(24);
    left_button.setFont(style);
    left_button.setColor(sf::Color::Red);
    left_button.setPosition(200, 360);

    right_button.setString("The button to move the player right is: " + moveright);
    right_button.setCharacterSize(24);
    right_button.setFont(style);
    right_button.setColor(sf::Color::Red);
    right_button.setPosition(200, 390);

    shoot_button.setString("The button to fire weapons is: " + shoot);
    shoot_button.setCharacterSize(24);
    shoot_button.setFont(style);
    shoot_button.setColor(sf::Color::Red);
    shoot_button.setPosition(200, 420);

    volume_level.setString("The volume is at " + std::to_string(volume) + " and can be changed with: " + volumeup + " and " + volumedown);
    volume_level.setCharacterSize(24);
    volume_level.setFont(style);
    volume_level.setColor(sf::Color::Red);
    volume_level.setPosition(200, 450);

    window.clear(sf::Color::Black);
    window.display();
	window.draw(up_button);
    window.draw(down_button);
    window.draw(left_button);
    window.draw(right_button);
    window.draw(shoot_button);
    window.draw(volume_level);
    window.draw(optionsSprite);
    window.display();
}