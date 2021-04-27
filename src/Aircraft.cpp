/// \file Aircraft.cpp
/// \author Rui Hou, Joey Lindsay, Harrison Keen, Kathy Ngo
/// \brief Source file for the Application class
/// \date 2021-04-02
#include "Aircraft.hpp"
#include <SFML/Graphics.hpp>

Aircraft::Aircraft(sf::Texture& texture, const sf::IntRect& sizeRect)
    : SceneNode(texture, sizeRect)
{
}

void Aircraft::fire(std::vector<PendingChange>& changeQueue)
{
    if (_fireCountdown <= sf::Time::Zero) {
        fireAction(changeQueue);
        _fireCountdown = _fireInterval;
    }
}

void Aircraft::fireAction(std::vector<PendingChange>& changeQueue)
{
}

void Aircraft::updateCurrent(sf::Time dt)
{
    if (_fireCountdown > sf::Time::Zero)
        _fireCountdown -= dt;
    SceneNode::updateCurrent(dt);
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(_sprite, state);
}

void Aircraft::damage(int damageValue)
{
    _health -= damageValue;
    if (_health <= 0)
        destroy();
}

int Aircraft::getHealth() const
{
    return _health;
}