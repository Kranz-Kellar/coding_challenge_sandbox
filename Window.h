#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "Camera.h"
#include "System.h"

class Window : public System
{

	GLFWwindow* windowPtr;
	const char* title;
	Camera* camera;

	void Init();
public:
	GLint width, height;
	Window(Camera* camera, int width, int height, const char* title);
	~Window();

	void Shutdown();
	void Update();
	void SwapBuffers();
	void SetCursor(bool value);

	bool windowShouldClose;

	GLFWwindow* GetWindowPointer() {
		return this->windowPtr;
	}

	void processEvent(Event* event) {
		switch (event->type) {
		case EV_DEBUG:
			std::cout << "WINDOW::EV_DEBUG" << std::endl;
			break;
		case EV_KEY_ESC:
			this->windowShouldClose = true;
			break;
		}
	}
	


};

