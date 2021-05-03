#pragma once

#include "Bullet.hpp"
#include "EnemyType.hpp"
#include "SceneNode.hpp"
#include "SFML/Graphics.hpp"
#include <vector>

struct Command {
    enum class Type {
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown,
        Fire,
        TimeStop,
        AddEnemy,
        Pause,
    };
    Command(Type type, SceneNode* entity);
    Type type;
    SceneNode* entity;
    EnemyType newEnemyType;
    sf::Vector2f position;
};
