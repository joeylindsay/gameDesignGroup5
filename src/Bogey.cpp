#include "Bogey.hpp"
#include "Aircraft.hpp"
#include "Bullet.hpp"
#include "TextureHolder.hpp"
#include <SFML/Graphics.hpp>

Bogey::Bogey(Context& context)
    : Aircraft { context.textures.get(TextureHolder::ID::Bogey), sf::IntRect { 0, 0, 125, 56 }, context }
    , _bulletTexture { context.textures.get(TextureHolder::ID::EnemyBullet) }
{
    _unitVelocity = 200.0f;
    _fireInterval = sf::seconds(0.4f);
    _health = 60;

    sf::FloatRect bounds { _sprite.getLocalBounds()};
    _sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

    _steps = { 
        {  0,  1 },
        {  0,  1 },
        { -1,  1 },
        { -1,  1 },
        { -1,  1 },

        {  1,  0 },
        {  1,  0 },
        {  1,  0 },
        {  1,  1 },
        {  1,  1 },

        {  0,  1 },
        {  0,  1 },
        {  0,  1 },
        {  0,  1 },
        {  0,  1 },
        {  0,  1 },
        {  0,  1 },

    };
}

void Bogey::fireAction(std::vector<PendingChange>& changeQueue)
{
    if (_fireCountdown <= sf::Time::Zero) {
        auto bulletPtr { std::make_unique<Bullet>(_bulletTexture, 20, 500.0f) };
        sf::Vector2f bulletPos { getPosition().x, getPosition().y - 7.0f };
        bulletPtr->setPosition(bulletPos);
        changeQueue.emplace_back(PendingChange::Type::AddBullet);
        changeQueue.back().newBullets.emplace_back(std::move(bulletPtr));

        _fireCountdown = _fireInterval;
    }
}
