#include "PlayerAircraft.hpp"
#include "Aircraft.hpp"
#include "Bullet.hpp"
#include "TextureHolder.hpp"
#include <SFML/Graphics.hpp>

PlayerAircraft::PlayerAircraft(TextureHolder& textures, float scrollSpeed)
    : Aircraft { textures.get(TextureHolder::ID::InterceptorAircraft), sf::IntRect { 0, 0, 70, 108 } }
    , _scrollSpeed { scrollSpeed }
    , _bulletTexture { textures.get(TextureHolder::ID::Bullet) }
{
    _unitVelocity = 300.0f;
    _velocity.y = -50.0f;

    sf::FloatRect bounds { _sprite.getLocalBounds()};
    _sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}

void PlayerAircraft::updateCurrent(sf::Time dt)
{
    _velocity.y += _scrollSpeed;
    Aircraft::updateCurrent(dt);
}

void PlayerAircraft::fireAction(std::vector<PendingChange>& changeQueue)
{
    auto bulletPtr { std::make_unique<Bullet>(_bulletTexture, 20, -500.0f) };
    sf::Vector2f bulletPos { getPosition().x, getPosition().y - _sprite.getLocalBounds().height / 2.0f };
    bulletPtr->setPosition(bulletPos);
    changeQueue.emplace_back(PendingChange::Type::AddBullet);
    changeQueue.back().newBullets.emplace_back(std::move(bulletPtr));
}
