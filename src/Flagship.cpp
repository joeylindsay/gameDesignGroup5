#include "Flagship.hpp"

Flagship::Flagship(Context& context)
    : Aircraft { context.textures.get(TextureHolder::ID::Flagship), sf::IntRect { 0, 0, 350, 194 }, context }
    , _bulletTexture { context.textures.get(TextureHolder::ID::EnemyBullet) }
    , _context { context }
{
    _unitVelocity = 75.0f;
    _fireInterval = sf::seconds(0.4f);
    _health = 500;

    sf::FloatRect bounds { _sprite.getLocalBounds()};
    _sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

    _steps = { 
        {  1,  0 },
        
        { -1,  0 },
        
        {  1, -1 },
        
        {  0, -1 },

    };
}

void Flagship::fireAction(std::vector<PendingChange>& changeQueue)
{
    if (_fireCountdown <= sf::Time::Zero) {
        auto bulletPtr { std::make_unique<Bullet>(_bulletTexture, 20, 500.0f) };
        sf::Vector2f bulletPos { getPosition().x, getPosition().y};
        bulletPtr->setPosition(bulletPos);
        changeQueue.emplace_back(PendingChange::Type::AddBullet);
        changeQueue.back().newBullets.emplace_back(std::move(bulletPtr));
        
        auto bulletPtr1 { std::make_unique<Bullet>(_bulletTexture, 20, 500.0f) };
        sf::Vector2f bulletPos1 { getPosition().x - 100.0f, getPosition().y};
        bulletPtr1->setPosition(bulletPos1);
        changeQueue.emplace_back(PendingChange::Type::AddBullet);
        changeQueue.back().newBullets.emplace_back(std::move(bulletPtr1));
        
        auto bulletPtr2 { std::make_unique<Bullet>(_bulletTexture, 20, 500.0f) };
        sf::Vector2f bulletPos2 { getPosition().x + 100.0f, getPosition().y};
        bulletPtr2->setPosition(bulletPos2);
        changeQueue.emplace_back(PendingChange::Type::AddBullet);
        changeQueue.back().newBullets.emplace_back(std::move(bulletPtr2));

        _fireCountdown = _fireInterval;
    }
}

//override function, necessary for keeping the flagship onscren until it is killed
const sf::Vector2i& Flagship::getNextStep(){
	const sf::Vector2i& step = _steps[_curStep];
    if (_curStep == 0 && (this->getBoundingRect().left + 350) >= 1080){
    	_curStep = 1;
    } else if (_curStep == 1 && this->getBoundingRect().left <= 0){
    	_curStep = 2;
    } else if (_curStep == 2 && this->getBoundingRect().left >= 170){
    	_curStep = 3;
    } else if (_curStep == 3 && this->getBoundingRect().top <= _context.worldTop){
    	_curStep = 0;
    }
       
    return step;
}
