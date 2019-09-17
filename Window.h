#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{

	GLFWwindow* windowPtr;
	const char* title;


	void Init();
	
public:
	GLint width, height;
	Window(int width, int height, const char* title);
	~Window();

	void Shutdown();
	void Update();
	void SwapBuffers();

	bool windowShouldClose;
};

