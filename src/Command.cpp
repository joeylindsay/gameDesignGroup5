#include "Command.hpp"

Command::Command(Type type, SceneNode* entity)
    : type(type)
    , entity(entity)
{
}
