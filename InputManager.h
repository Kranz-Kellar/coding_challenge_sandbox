#pragma once


#include <GLFW/glfw3.h>
#include "System.h"
#include "EventManager.h"
#include "events/KeyboardEvent.h"
#include "events/MouseEvent.h"
#include <functional>

class InputManager : public System
{
public:

	void processEvent(Event* event) {
		switch (event->type) {
		case EV_KEYBOARD:
			std::cout << "IM::KEYBOARD_EVENT" << std::endl;
			processKeyboardEvent(static_cast<KeyboardEvent*>(event));
			break;
		case EV_MOUSE:
			std::cout << "IM::MOUSE_EVENT" << std::endl;
			break;
		case EV_SYSTEM:
			std::cout << "IM::SYSTEM_EVENT" << std::endl;
			break;
		case EV_NONE:
			std::cout << "CHECK EVENTS CONSTRUCTOR! U FORGOT TYPE ASSIGN!" << std::endl;
			break;
		}
	}


	std::function<void(int, int, int, int)> keyPressed = [&](auto key, auto scancode, auto action, auto mode) {
		KeyboardEvent* event = new KeyboardEvent(key, scancode, action, mode);
		EventManager::InvokeEvent(event);
	};

	std::function<void(double, double)> mouseCallback = [&](auto xpos, auto ypos) {
		//std::cout << "Mouse x: " << xpos << std::endl;
		//std::cout << "Mouse y: " << ypos << std::endl;
		//camera->ProcessMouseMovement(xpos, ypos);

		MouseEvent* event = new MouseEvent(xpos, ypos);
		EventManager::InvokeEvent(event);
	};

	void processKeyboardEvent(KeyboardEvent* event) {

		switch (event->keyboardState.key) {
		case GLFW_KEY_W:
			std::cout << "IM::KEY_W" << std::endl;
			break;
		}
	}

};

