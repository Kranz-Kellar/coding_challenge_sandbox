#include "InputManager.h"

InputManager::InputManager()
{
	subscribeOnEvents();
}

void InputManager::subscribeOnEvents()
{
	subscribeOnEventType(EV_KEYBOARD);
	subscribeOnEventType(EV_MOUSE);
	subscribeOnEventType(EV_NONE);
}

void InputManager::processEvent(Event* event) {
	switch (event->type) {
	case EV_KEYBOARD:
		Logger::Log("IM::KEYBOARD_EVENT", LOG_DEBUG);
		processKeyboardEvent(static_cast<KeyboardEvent*>(event));
		break;
	case EV_MOUSE:
		Logger::Log("IM::MOUSE_EVENT", LOG_DEBUG);
		break;
	case EV_SYSTEM:
		Logger::Log("IM::SYSTEM_EVENT", LOG_DEBUG);
		break;
	case EV_NONE:
		Logger::Log("CHECK EVENTS CONSTRUCTOR! EVENT TYPE IS NULL!", LOG_DEBUG);
		break;
	}
}



void InputManager::processKeyboardEvent(KeyboardEvent* event) {

	switch (event->keyboardState.key) {
	case GLFW_KEY_W:
		std::cout << "IM::KEY_W" << std::endl;
		break;
	}
}
