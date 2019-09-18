#pragma once


#include <GLFW/glfw3.h>
#include "System.h"
#include "EventManager.h"
#include <functional>

class InputManager : public System
{
public:

	void processEvent(Event* event) {
		switch (event->type) {
		case EV_DEBUG:
			std::cout << "Input manager::DEBUG_EVENT" << std::endl;
			break;
		case EV_KEY_W:
			std::cout << "IM::KEY_W" << std::endl;
			break;
		case EV_KEY_S:
			std::cout << "IM::KEY_S" << std::endl;
			break;
		case EV_KEY_A:
			std::cout << "IM::KEY_A" << std::endl;
			break;
		case EV_KEY_D:
			std::cout << "IM::KEY_D" << std::endl;
			break;
		}
	}


	std::function<void(int, int, int, int)> keyPressed = [&](auto key, auto scancode, auto action, auto mode) {

		if (key == GLFW_KEY_W) {
			std::cout << "KEY_W" << std::endl;
			Event* keyEvent = new Event(EV_KEY_W);
			EventManager::InvokeEvent(keyEvent);
		}

		if (key == GLFW_KEY_D) {
			Event* keyEvent = new Event(EV_KEY_A);
			EventManager::InvokeEvent(keyEvent);
		}

		if (key == GLFW_KEY_A) {
			Event* keyEvent = new Event(EV_KEY_S);
			EventManager::InvokeEvent(keyEvent);
		}

		if (key == GLFW_KEY_S) {
			Event* keyEvent = new Event(EV_KEY_D);
			EventManager::InvokeEvent(keyEvent);
		}

		if (key == GLFW_KEY_ESCAPE) {
			Event* keyEvent = new Event(EV_KEY_ESC);
			EventManager::InvokeEvent(keyEvent);
		}
	};

	std::function<void(double, double)> mouseCallback = [&](auto xpos, auto ypos) {
		std::cout << "Mouse x: " << xpos << std::endl;
		std::cout << "Mouse y: " << ypos << std::endl;
		//camera->ProcessMouseMovement(xpos, ypos);
	};

};

