//main file for the winscreen

#include <winScreen.hpp>

interceptors::winScreen::winScreen(int score){
	using interceptors::winScreen;
	//TODO
    sf::Texture lose;
    lose.loadFromFile("../assets/interceptorsprite.png");
    winScreenSprite.setTexture(lose);
}

void interceptors::winScreen::show(sf::RenderWindow& window){
	using interceptors::winScreen;
	//TODO
    sf::Text win_declaration;
    sf::Text final_score;

    sf::Font style;
    if (!style.loadFromFile("../assets/Arial.ttf")) {
        std::cout << "Font not located." << std::endl;
    }

    win_declaration.setString("You win!");
    win_declaration.setCharacterSize(48);
    win_declaration.setFont(style);
    win_declaration.setColor(sf::Color::Red);
    win_declaration.setPosition(200, 300);

    final_score.setString("Your score: " + score);
    final_score.setCharacterSize(24);
    final_score.setFont(style);
    final_score.setColor(sf::Color::Red);
    final_score.setPosition(200, 400);

    winScreenSprite.setPosition(200, 150);

    window.clear(sf::Color::Black);
    window.display();
    window.draw(final_score);
    window.draw(winScreenSprite);
    window.display();
}
