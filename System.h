#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include "events/Event.h"

namespace Erbium {

	class Module
	{
	protected:
		std::vector<EventType> subscribedEvents;
	public:

		void subscribeOnEventType(EventType type) {
			if (!isSubscribedOnEventType(type)) {
				subscribedEvents.push_back(type);
			}
		}

		bool isSubscribedOnEventType(EventType type) {
			std::vector<EventType>::iterator it = std::find(subscribedEvents.begin(), subscribedEvents.end(), type);
			if (it != subscribedEvents.end()) {
				return true;
			}
			return false;
		}

		virtual void  processEvent(Event* event) {}

		virtual void Destroy() {}
	};

}