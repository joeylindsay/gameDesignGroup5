#pragma once

#include "SceneNode.hpp"
#include <SFML/Graphics.hpp>

class Bullet : public SceneNode
{
public:
    Bullet(sf::Texture& texture, int power, float verticalVelocity);
    void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override final;
    int getDamageValue() const override final;

private:
    int _power;
};
