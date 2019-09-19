#pragma once

#include "Event.h"


struct GLFWmouseState {
	double xpos;
	double ypos;
};


class MouseEvent : public Event
{
public:
	GLFWmouseState mouseState;

	MouseEvent(double xpos, double ypos) {
		mouseState.xpos = xpos;
		mouseState.ypos = ypos;

		type = EV_MOUSE;
	}
};

