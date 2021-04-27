//The main file for the menu implementation

#include <menu.hpp>

interceptors::menu::menu(){
	using interceptors::menu;
	//TODO
    sf::Texture menu;
    menu.loadFromFile("../assets/interceptorsprite.png"); // replace with correct menu sprite file
    menuScreen.setTexture(menu);
}

void interceptors::menu::handleInput(sf::Event event) {
    using interceptors::menu;
    if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Space) {
            m_choice = m_play;
        }
        else if (event.key.code == sf::Keyboard::I) {
            m_choice = m_info;
        }
        else if (event.key.code == sf::Keyboard::O) {
            m_choice = m_options;
        }
        else if (event.key.code == sf::Keyboard::Escape) {
            m_choice = m_quit;
        }
    }
//    switch(m_choice) {
//        case m_play: ;
//        case m_info: ;
//        case m_options: ;
//        case m_quit: ;
//    }
}

void interceptors::menu::show(sf::RenderWindow& window){
	using interceptors::menu;
	//TODO
    sf::Text play_button;
    sf::Text info_button;
    sf::Text options_button;
    sf::Text quit_button;

    sf::Font style;
    if (!style.loadFromFile("../assets/Arial.ttf")) {
        std::cout << "Font not located." << std::endl;
    }

    play_button.setString("Go back to playing the game with the Spacebar.");
    play_button.setCharacterSize(24);
    play_button.setFont(style);
    play_button.setColor(sf::Color::Red);
    play_button.setPosition(200, 300);

    info_button.setString("Pull up information with I.");
    info_button.setCharacterSize(24);
    info_button.setFont(style);
    info_button.setColor(sf::Color::Red);
    info_button.setPosition(200, 330);

    options_button.setString("Go to the Options screen with O.");
    options_button.setCharacterSize(24);
    options_button.setFont(style);
    options_button.setColor(sf::Color::Red);
    options_button.setPosition(200, 360);

    quit_button.setString("Quit the game with Escape.");
    quit_button.setCharacterSize(24);
    quit_button.setFont(style);
    quit_button.setColor(sf::Color::Red);
    quit_button.setPosition(200, 390);

    menuScreen.setPosition(200, 250);

    window.clear(sf::Color::Black);
    window.display();
    window.draw(play_button);
    window.draw(info_button);
    window.draw(options_button);
    window.draw(quit_button);
    window.draw(menuScreen);
    window.display();
}

