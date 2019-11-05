#pragma once


#include <GLFW/glfw3.h>
#include "System.h"
#include "EventManager.h"
#include "events/KeyboardEvent.h"
#include "events/MouseEvent.h"
#include "Logger.h"
#include <functional>

namespace Erbium {

	class InputManager : public Module
	{
		void subscribeOnEvents();
		void processKeyboardEvent(KeyboardEvent* event);
	public:

		InputManager();

		void processEvent(Event* event);


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

	};

}