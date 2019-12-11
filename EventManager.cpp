#include "EventManager.h"

using namespace Erbium;

std::queue<Event*> EventManager::eventQueue;
std::vector<Module*> EventManager::engineSystems;