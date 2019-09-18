#include "Window.h"




Window::Window(Camera* camera, int width, int height, const char* title)
{
	this->camera = camera;
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
	glfwSetWindowUserPointer(windowPtr, this);
	glfwMakeContextCurrent(this->windowPtr);

	//Load glew here
	glewExperimental = GL_TRUE;
	if (!glewInit() == GLEW_OK) {
		std::cout << "GLEW INIT ERROR" << std::endl;

		Shutdown();
		return;
	}

	glViewport(0, 0, this->width, this->height);

	//Немного магии
#define genericCallback(functionName)\
	[](GLFWwindow* window, const auto... args) {\
		const auto ptr = static_cast<Window*>(glfwGetWindowUserPointer(window));\
		if (ptr->functionName) {\
			ptr->functionName(args...); }\
	}

	glfwSetKeyCallback(this->windowPtr, genericCallback(keyPressed));
	glfwSetCursorPosCallback(this->windowPtr, genericCallback(mouseCallback));
}

void Window::Update()
{
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	if (glfwWindowShouldClose(this->windowPtr)) {
		this->windowShouldClose = true;
		glfwSetWindowShouldClose(this->windowPtr, this->windowShouldClose);
	}
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(this->windowPtr);
}

void Window::SetCursor(bool value)
{
	if (value == true) {
		glfwSetInputMode(windowPtr, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
	else {
		glfwSetInputMode(windowPtr, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}

}

void Window::Shutdown()
{
	glfwDestroyWindow(this->windowPtr);
	glfwTerminate();
}

