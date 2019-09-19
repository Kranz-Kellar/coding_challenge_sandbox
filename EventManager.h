#pragma once

#include <queue>
#include <vector>
#include "events/Event.h"
#include "System.h"

class EventManager
{
	static std::queue<Event*> eventQueue;
	static std::vector<System*> engineSystems;

public:

	static void InvokeEvent(Event* event) {
		EventManager::eventQueue.push(event);
	}

	static void ProcessEvents() {
		for (size_t i = 0; i < EventManager::eventQueue.size(); i++) {
			Event* event = EventManager::eventQueue.front();
			for (auto system : engineSystems) {
				if (system->isSubscribedOnEventType(event->type)) {
					system->processEvent(event);
				}
			}
			EventManager::eventQueue.pop();
		}
	}

	static void AddSystem(System* system) {
		engineSystems.push_back(system);
	}

};

