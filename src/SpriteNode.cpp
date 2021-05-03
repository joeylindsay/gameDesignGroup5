#include "SpriteNode.hpp"
#include <SFML/Graphics.hpp>

SpriteNode::SpriteNode(const sf::Texture& texture, const sf::IntRect& sizeRect)
    : SceneNode(texture, sizeRect)
{
}

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(_sprite);
}
