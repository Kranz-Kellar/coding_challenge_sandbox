#pragma once

#include <queue>
#include <vector>
#include "events/Event.h"
#include "System.h"

namespace Erbium {

	class EventManager
	{
		static std::queue<Event*> eventQueue;
		static std::vector<Module*> engineSystems;

	public:

		static void InvokeEvent(Event* event) {
			EventManager::eventQueue.push(event);
			std::cout << "Pushing event. Size of event queue is " << sizeof(eventQueue) << std::endl;
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
				delete event;
			}
		}

		static void AddSystem(Module* system) {
			engineSystems.push_back(system);
		}

	};

}
