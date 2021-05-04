#include "Command.hpp"
//constructor for passing non-entity related commands
Command::Command(Type type)
	: type(type)
{
}

//constructor for passing entity commands
Command::Command(Type type, SceneNode* entity)
    : type(type)
    , entity(entity)
{
}
