//main file for the losescreen

#include <loseScreen.hpp>

interceptors::loseScreen::loseScreen(int score) {
	using interceptors::loseScreen;
	//TODO
    sf::Texture lose;
    lose.loadFromFile("../assets/interceptorsprite.png");
    loseScreenSprite.setTexture(lose);
}

void interceptors::loseScreen::show(sf::RenderWindow& window) {
	using interceptors::loseScreen;
	//TODO
	sf::Text loss_declaration;
    sf::Text final_score;

    sf::Font style;
    if (!style.loadFromFile("../assets/Arial.ttf")) {
        std::cout << "Font not located." << std::endl;
    }

    loss_declaration.setString("You lost!");
    loss_declaration.setCharacterSize(48);
    loss_declaration.setFont(style);
    loss_declaration.setColor(sf::Color::Red);
    loss_declaration.setPosition(200, 300);

    final_score.setString("Your score: " + score);
    final_score.setCharacterSize(24);
    final_score.setFont(style);
    final_score.setColor(sf::Color::Red);
    final_score.setPosition(200, 400);

    loseScreenSprite.setPosition(200, 150);

    window.clear(sf::Color::Black);
    window.display();
    window.draw(final_score);
    window.draw(loseScreenSprite);
    window.display();
}
