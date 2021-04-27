#pragma once

#include "SceneNode.hpp"
#include <SFML/Graphics.hpp>

class SpriteNode : public SceneNode
{
public:
    SpriteNode(const sf::Texture& texture, const sf::IntRect& sizeRect);
protected:
    void drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const override;
};
