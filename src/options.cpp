//the main file for the options screen

#include <options.hpp>

interceptors::options::options(){
	using interceptors::options;
	//TODO
    volume = 25;
    moveup = 'Up';
    movedown = 'Down';
    moveleft = 'Left';
    moveright = 'Right';
    shoot = 'Space';

    m_scale = 1;
    m_winsizeX = 800;
    m_winsizeY = 600;
    optionsSprite;
}

void interceptors::options::show(sf::RenderWindow& window){
	using interceptors::options;
	//TODO
	//sf::Text up_button;
    //sf::Text down_button;
    //sf::Text left_button;
    //sf::Text right_button;
    //sf::Text shoot_button;
    //sf::Text volume_level;

    //sf::Font style;
    //if (!style.loadFromFile("font name")) {
    //    std::cout << "Font not located." << std::endl;
    //}

    //up_button.setString("The button to move the player forward is:" + moveup);
    //up_button.setCharacterSize(24);
    //up_button.setFont(style);
    //up_button.setColor(sf::Color::Red);
    //up_button.setPosition(200, 300);

    //down_button.setString("The button to move the player backward is:" + movedown);
    //down_button.setCharacterSize(24);
    //down_button.setFont(style);
    //down_button.setColor(sf::Color::Red);
    //down_button.setPosition(200, 330);

    //left_button.setString("The button to move the player left is:" + moveleft);
    //left_button.setCharacterSize(24);
    //left_button.setFont(style);
    //left_button.setColor(sf::Color::Red);
    //left_button.setPosition(200, 360);

    //right_button.setString("The button to move the player right is:" + moveright);
    //right_button.setCharacterSize(24);
    //right_button.setFont(style);
    //right_button.setColor(sf::Color::Red);
    //right_button.setPosition(200, 390);

    //shoot_button.setString("The button to fire weapons is:" + shoot);
    //shoot_button.setCharacterSize(24);
    //shoot_button.setFont(style);
    //shoot_button.setColor(sf::Color::Red);
    //shoot_button.setPosition(200, 420);

    //volume_level.setString("The volume is at:" + volume);
    //volume_level.setCharacterSize(24);
    //volume_level.setFont(style);
    //volume_level.setColor(sf::Color::Red);
    //volume_level.setPosition(200, 450);

    //window.setSize(winsizeX, winsizeY);

	//window.draw(up_button);
    //window.draw(down_button);
    //window.draw(left_button);
    //window.draw(right_button);
    //window.draw(shoot_button);
    //window.draw(volume_level);
    //window.draw(optionsSprite);
    //window.display();
}