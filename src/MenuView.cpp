#include "MenuView.hpp"

MenuView::MenuView(Context& context)
    : GameView {}
    , _context { context }
    , _backgroundSprite { _context.textures.get(TextureHolder::ID::TitleBackground) }
    , _titleText { "Interceptors", _context.fonts.get(FontHolder::ID::Arcade) }
    , _startButtonText { "START", _context.fonts.get(FontHolder::ID::Arcade) }
{
    _titleText.setPosition(sf::Vector2f { 100.0f, 300.0f });
    _titleText.setCharacterSize(90);

    _startButton.setSize(sf::Vector2f { 300.0f, 100.0f });
    _startButton.setPosition(sf::Vector2f { 234.0f, 700.0f });
    _startButton.setFillColor(sf::Color::Green);

    _startButtonText.setPosition(sf::Vector2f { 285.0f, 700.0f });
    _startButtonText.setCharacterSize(70);
}

void MenuView::update(sf::Time dt, GameStateID state, const sf::FloatRect& worldBounds, std::vector<Command>& commandQueue)
{
    sf::RenderWindow& window { _context.window };
    if (state != GameStateID::Menu) {
        return;
    }
    window.draw(_backgroundSprite);
    window.draw(_titleText);
    window.draw(_startButton);
    window.draw(_startButtonText);
}
