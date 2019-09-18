#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <functional>
#include <iostream>
#include "Camera.h"

class Window
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


	std::function<void(int, int, int, int)> keyPressed = [&](auto key, auto scancode, auto action, auto mode) {
		std::cout << "W KEY" << std::endl;
		if (key == GLFW_KEY_ESCAPE) {
			glfwSetWindowShouldClose(windowPtr, true);
		}
	};

	std::function<void(double, double)> mouseCallback = [&](auto xpos, auto ypos) {
		std::cout << "Mouse x: " << xpos << std::endl;
		std::cout << "Mouse y: " << ypos << std::endl;
		camera->ProcessMouseMovement(xpos, ypos);
	};


};

