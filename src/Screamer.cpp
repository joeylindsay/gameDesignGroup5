#include "Screamer.hpp"
#include "Aircraft.hpp"
#include "Bullet.hpp"
#include "TextureHolder.hpp"
#include <SFML/Graphics.hpp>

Screamer::Screamer(TextureHolder& textures)
        : Aircraft { textures.get(TextureHolder::ID::Screamer), sf::IntRect { 0, 0, 100, 108 } }
        , _bulletTexture { textures.get(TextureHolder::ID::EnemyBullet) }
{
    _unitVelocity = 300.0f;
    _fireInterval = sf::seconds(0.4f);
    _health = 40;

    sf::FloatRect bounds { _sprite.getLocalBounds()};
    _sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}

void Screamer::fireAction(std::vector<PendingChange>& changeQueue)
{
    if (_fireCountdown <= sf::Time::Zero) {
        auto bulletPtr { std::make_unique<Bullet>(_bulletTexture, 20, 500.0f) };
        sf::Vector2f bulletPos { getPosition().x, getPosition().y - _sprite.getLocalBounds().height / 2.0f };
        bulletPtr->setPosition(bulletPos);
        changeQueue.emplace_back(PendingChange::Type::AddBullet);
        changeQueue.back().newBullets.emplace_back(std::move(bulletPtr));

        _fireCountdown = _fireInterval;
    }
}
