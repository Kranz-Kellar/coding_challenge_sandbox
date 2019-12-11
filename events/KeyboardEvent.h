#pragma once
#include "Event.h"

namespace Erbium {

	struct GLFWkeyboardState {
		int key;
		int scancode;
		int action;
		int mode;
	};

	class KeyboardEvent : public Event
	{

	public:
		GLFWkeyboardState keyboardState;


		KeyboardEvent(int key, int scancode, int action, int mode) {
			keyboardState.key = key;
			keyboardState.scancode = scancode;
			keyboardState.action = action;
			keyboardState.mode = mode;

			type = EV_KEYBOARD;
		}

	};

}