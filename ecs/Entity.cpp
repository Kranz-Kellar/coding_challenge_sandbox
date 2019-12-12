#include "Entity.h"

using namespace Erbium;

Entity::Entity() : id()
{
#ifdef _DEBUG
	Logger::Log("Entity was created", LOG_DEBUG);
#endif
}

Entity::~Entity() {
#ifdef _DEBUG
	Logger::Log("Entity was destroyed", LOG_DEBUG);
#endif
}
