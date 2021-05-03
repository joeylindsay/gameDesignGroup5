/// \file SceneNode.hpp
/// \author Rui Hou, Joey Lindsay, Harrison Keen, Kathy Ngo
/// \brief Header file for the SceneNode class
/// \date 2021-04-02
#pragma once

#include <SFML/Graphics.hpp>
#include <list>

/// A node of the scene graph. Renders and updates with hierachy.
class SceneNode : public sf::Drawable, public sf::Transformable, private sf::NonCopyable {
    friend class AIView;
public:
    SceneNode();
    SceneNode(const sf::Texture& texture);
    SceneNode(const sf::Texture& texture, const sf::IntRect& sizeRect);
    /// Renders the current node and its children. DFS of the subtree. Leftmost child rendered first.
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override final;
    /// Take ownership from ptr and attach as child.
    void attach(std::unique_ptr<SceneNode> ptr);
    std::list<std::unique_ptr<SceneNode>>& getChildren();
    /// Update subtree for moves, etc.
    void update(sf::Time dt);
    /// Clear the velocity to 0
    void resetVelocity();
    /// Set velocity. Wait for adaptVelocity to change for concrete value.
    void setUnitVelocity(int x, int y);
    /// Return velocity of object.
    sf::Vector2f getVelocity() const;
    /// Apply the unit velocity
    void adaptVelocity();
    /// Get a bounding box in world coordinates.
    sf::FloatRect getBoundingRect() const;
    /// Clean up out of sight or destroyed nodes.
    void cleanUp(const sf::FloatRect& worldBounds);
    /// Returns the world transformation
    sf::Transform getWorldTransform() const;
    /// Mark node as destroyed
    void destroy();
    /// Deal damage to this node.
    virtual void damage(int damagePt);
    /// Check if this node collides with rhs. If so, deal the damage
    bool checkCollision(const sf::FloatRect& rhs, int damageValue);
    bool isDestroyed() const;
    /// Returns the damage this node would deal to others if collides
    virtual int getDamageValue() const;
    int _unitVelocity;

protected:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);
    sf::Sprite _sprite;
    std::list<std::unique_ptr<SceneNode>> _children;
    SceneNode* _parent { nullptr };
    sf::Vector2f _velocity { 0.0f, 0.0f };
    bool _destroyed { false };
};
