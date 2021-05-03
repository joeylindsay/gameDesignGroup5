#pragma once

#include "Bullet.hpp"
#include "SceneNode.hpp"
#include <vector>

struct PendingChange
{
    enum class Type {
        AddBullet,
        AddEnemy
    };
    PendingChange(Type type);
    Type type;
    std::vector<std::unique_ptr<Bullet>> newBullets;
    std::unique_ptr<SceneNode> newNode { nullptr };
};
