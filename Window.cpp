#include "Window.h"
#include <iostream>

///#define genericInputCallback(functionName)\
	[](GLFWwindow* window, const auto... args) {\
		const auto ptr = static_cast<Input*>(glfwGetWindowUserPointer(window));\
		if (ptr->functionName) { ptr->functionName(args...); }\
	}

Window::Window(int width, int height, const char* title)
{
	this->width = width;
	this->height = height;
	this->title = title;
	this->windowShouldClose = false;

	Init();
}


Window::~Window()
{
	Shutdown();
}

void Window::Init()
{
	if (!glfwInit()) {
		std::cout << "GLFW INIT ERROR" << std::endl;
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	this->windowPtr = glfwCreateWindow(this->width, this->height, this->title, NULL, NULL);
	if (this->windowPtr == nullptr) {
		std::cout << "WINDOW CREATE ERROR" << std::endl;
		//Log error here

		Shutdown();
		return;
	}

	glfwMakeContextCurrent(this->windowPtr);

	//Load glew here
	glewExperimental = GL_TRUE;
	if (!glewInit() == GLEW_OK) {
		std::cout << "GLEW INIT ERROR" << std::endl;

		Shutdown();
		return;
	}

	glViewport(0, 0, this->width, this->height);




}

void Window::Update()
{
	glfwPollEvents();



	if (glfwWindowShouldClose(this->windowPtr)) {
		this->windowShouldClose = true;
		glfwSetWindowShouldClose(this->windowPtr, this->windowShouldClose);
	}
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(this->windowPtr);
}

void Window::Shutdown()
{
	glfwDestroyWindow(this->windowPtr);
	glfwTerminate();
}