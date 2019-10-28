#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "Logger.h"
#include "Camera.h"
#include "System.h"
#include "events/KeyboardEvent.h"
#include "events/MouseEvent.h"

struct WindowAttributes {
	const char* title;
	GLuint width;
	GLuint height;
};

class Window : public System
{

	GLFWwindow* windowPtr;
	GLFWcursor* cursorPtr;
	const char* title;
	WindowAttributes attributes;
	Camera* camera;
	

	void Init();
	void SubscribeOnEvents();
	void InitGLFW();
	void CreateWindow();
	void LoadGLEW();
	void SetGenericGLFWCallbackForInputManager();
	void CreateAndSetStandartCursor();
	void Shutdown();
public:
	
	Window(Camera* camera, int width, int height, const char* title);
	~Window();

	void Destroy();
	void Update();
	void SwapBuffers();
	void SetCursor(bool value);

	bool windowShouldClose;

	GLFWwindow* GetWindowPointer() {
		return this->windowPtr;
	}

	void processEvent(Event* event) {
		switch (event->type) {
		case EV_KEYBOARD:
			std::cout << "WINDOW::KEYBOARD_EVENT" << std::endl;
			processKeyboardEvent(static_cast<KeyboardEvent*>(event));
			break;
		case EV_MOUSE:
			std::cout << "WINDOW::MOUSE_EVENT" << std::endl;
			processMouseEvent(static_cast<MouseEvent*>(event));
			break;
		}
	}
	
	void processKeyboardEvent(KeyboardEvent* event) {
		if (event == nullptr) {
			return;
		}

		//Позже пристроим сюда вычисление нормальной дельты.
#define DELTA_TIME 0.05f

		if (event->keyboardState.key == GLFW_KEY_W) {
			camera->ProcessKeyboard(UP, DELTA_TIME);
		}
		if (event->keyboardState.key == GLFW_KEY_A) {
			camera->ProcessKeyboard(LEFT, DELTA_TIME);
		}
		if (event->keyboardState.key == GLFW_KEY_S) {
			camera->ProcessKeyboard(DOWN, DELTA_TIME);
		}
		if (event->keyboardState.key == GLFW_KEY_D) {
			camera->ProcessKeyboard(RIGHT, DELTA_TIME);
		}

		if (event->keyboardState.key == GLFW_KEY_ESCAPE) {
			this->windowShouldClose = true;
		}
	}

	void processMouseEvent(MouseEvent* event) {

		if (event == nullptr)
			return;

		camera->ProcessMouseMovement(event->mouseState.xpos, event->mouseState.ypos);
	}

	

};

