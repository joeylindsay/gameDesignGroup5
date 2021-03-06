/// \file Aircraft.cpp
/// \author Rui Hou, Joey Lindsay, Harrison Keen, Kathy Ngo
/// \brief Source file for the Application class
/// \date 2021-04-02
#include "Aircraft.hpp"

Aircraft::Aircraft(sf::Texture& texture, const sf::IntRect& sizeRect, Context& context)
    : SceneNode(texture, sizeRect)
    , _context{ context }
{
}

bool Aircraft::fire(std::vector<PendingChange>& changeQueue)
{
    if (_fireCountdown <= sf::Time::Zero) {
        fireAction(changeQueue);
        _fireCountdown = _fireInterval;
        return true;
    }
    return false;
}

void Aircraft::fireAction(std::vector<PendingChange>& changeQueue)
{
}

void Aircraft::updateCurrent(sf::Time dt, bool timeStop)
{
    if (_fireCountdown > sf::Time::Zero)
        _fireCountdown -= dt;
    SceneNode::updateCurrent(dt, timeStop);
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(_sprite, state);
}

void Aircraft::damage(int damageValue)
{
    _health -= damageValue;
    if (_health <= 0){
        destroy();
        _context.score += 100;
    }
}

int Aircraft::getHealth() const
{
    return _health;
}

const sf::Vector2i& Aircraft::getNextStep()
{
    const sf::Vector2i& step = _steps[_curStep];
    if (count % 200 == 0) 
        _curStep = (_curStep + 1) % _steps.size();

    if (count > 1000)
        count = 0;

    count++;
    return step;
}
