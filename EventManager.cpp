#include "EventManager.h"

std::queue<Event*> EventManager::eventQueue;
std::vector<System*> EventManager::engineSystems;