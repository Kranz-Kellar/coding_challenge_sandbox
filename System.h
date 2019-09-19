#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include "events/Event.h"


class System
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

	virtual void  processEvent(Event* event) {
		std::cout << "EVENT OF TYPE " << event->type << " HAS BEEN ARRIVED!" << std::endl;
	}


};

