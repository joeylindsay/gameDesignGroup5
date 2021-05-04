/// \file SceneNode.cpp
/// \author Rui Hou, Joey Lindsay, Harrison Keen, Kathy Ngo
/// \brief Source file for the SceneNode class
/// \date 2021-04-02
#define _USE_MATH_DEFINES // switch to <numbers> in C++20

#include "SceneNode.hpp"

SceneNode::SceneNode()
{
    // No action
}

SceneNode::SceneNode(const sf::Texture& texture)
    : _sprite(texture)
{
    // No action
}

SceneNode::SceneNode(const sf::Texture& texture, const sf::IntRect& sizeRect)
    : _sprite(texture, sizeRect)
{
    // No action
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    drawCurrent(target, states);

    for (auto& child : _children)
        child->draw(target, states);
}

void SceneNode::attach(std::unique_ptr<SceneNode> ptr)
{
    ptr->_parent = this;
    _children.emplace_back(std::move(ptr));
}

void SceneNode::resetVelocity()
{
    _velocity = {0.0f, 0.0f};
    for (auto& child : _children)
        child->resetVelocity();
}

void SceneNode::setUnitVelocity(int x, int y)
{
    if (x != 0)
        _velocity.x = x;
    if (y != 0)
        _velocity.y = y;
}

void SceneNode::adaptVelocity()
{
    if (_velocity.x != 0 && _velocity.y != 0) {
        _velocity.x /= M_SQRT2;
        _velocity.y /= M_SQRT2;
    }
    _velocity.x *= _unitVelocity;
    _velocity.y *= _unitVelocity;

    for (auto& child : _children)
        child->adaptVelocity();
}

void SceneNode::update(sf::Time dt)
{
    updateCurrent(dt);
    for (auto& child : _children)
        child->update(dt);
}

void SceneNode::updateCurrent(sf::Time dt)
{
    move(_velocity * dt.asSeconds());
}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    // No action
}

void SceneNode::cleanUp(const sf::FloatRect& worldBounds)
{
    std::vector<decltype(_children.begin())> toRemove;

    for (auto iter = _children.begin(); iter != _children.end(); iter = std::next(iter))
        if ((*iter)->isDestroyed() || !(*iter)->getBoundingRect().intersects(worldBounds))
            toRemove.push_back(iter);
    
    for (auto iter : toRemove) {
        for (auto& child : (*iter)->_children)
            child->_parent = this;
        _children.merge((*iter)->_children);
        _children.erase(iter);
    }

    for (auto& child : _children)
        child->cleanUp(worldBounds);
}

sf::FloatRect SceneNode::getBoundingRect() const
{
    sf::FloatRect res = getWorldTransform().transformRect(_sprite.getGlobalBounds());
    return res;
}

sf::Transform SceneNode::getWorldTransform() const
{
    sf::Transform transform = sf::Transform::Identity;
    for (const SceneNode* ptr = this; ptr; ptr = ptr->_parent)
        transform *= ptr->getTransform();
    return transform;
}

std::list<std::unique_ptr<SceneNode>>& SceneNode::getChildren()
{
    return _children;
}

sf::Vector2f SceneNode::getVelocity() const
{
    return _velocity;
}

void SceneNode::destroy()
{
    _destroyed = true;
}

bool SceneNode::isDestroyed() const
{
    return _destroyed;
}

bool SceneNode::checkCollision(const sf::FloatRect& rhs, int damageValue)
{
    if (getBoundingRect().intersects(rhs)) {
        damage(damageValue);
        return true;
    }
    for (auto& child : _children)
        if (child->checkCollision(rhs, damageValue))
            return true;
    return false;
}

void SceneNode::damage(int damageValue)
{
    // No action
}

int SceneNode::getDamageValue() const
{
    return 0;
}
