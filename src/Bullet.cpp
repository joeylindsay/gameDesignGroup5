#include "Bullet.hpp"
#include <SFML/Graphics.hpp>

Bullet::Bullet(sf::Texture& texture, int power, float verticalVelocity)
    : SceneNode(texture)
    , _power { power }
{
    _velocity.y = verticalVelocity;
    sf::FloatRect bounds { _sprite.getLocalBounds()};
    _sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}

void Bullet::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

int Bullet::getDamageValue() const
{
    return _power;
}

void Bullet::updateCurrent(sf::Time dt, bool timeStop)
{
    if (_velocity.y < 0 || !timeStop)
        move(_velocity * dt.asSeconds());
}
