#include "Window.h"
#include "InputManager.h"



Window::Window(Camera* camera, int width, int height, const char* title)
{
	this->attributes.title = title;
	this->attributes.width = width;
	this->attributes.height = height;
	this->camera = camera;
	this->windowShouldClose = false;

	Init();
}


Window::~Window()
{
	Shutdown();
}

void Window::Init()
{
	InitGLFW();

	CreateWindow();

	glfwMakeContextCurrent(this->windowPtr);

	LoadGLEW();

	glViewport(0, 0, this->attributes.width, this->attributes.height);

	SetGenericGLFWCallbackForInputManager();

	CreateAndSetStandartCursor();

	SubscribeOnEvents();

	SetCursor(false);
}

void Window::InitGLFW() {
	if (!glfwInit()) {
		Logger::Log("GLFW init error", LOG_ERROR);
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Window::CreateWindow() {
	this->windowPtr = glfwCreateWindow(this->attributes.width, this->attributes.height, this->attributes.title, NULL, NULL);
	if (this->windowPtr == nullptr) {
		Logger::Log("glfwCreateWindow error", LOG_ERROR);
		Shutdown();
		return;
	}
}

void Window::LoadGLEW() {
	//Load glew here
	glewExperimental = GL_TRUE;
	if (!glewInit() == GLEW_OK) {
		std::cout << "GLEW INIT ERROR" << std::endl;

		Shutdown();
		return;
	}
}

void Window::SetGenericGLFWCallbackForInputManager() {
#define genericCallback(functionName)\
	[](GLFWwindow* window, const auto... args) {\
		const auto ptr = static_cast<InputManager*>(glfwGetWindowUserPointer(window));\
		if (ptr->functionName) {\
			ptr->functionName(args...); }\
	}

	glfwSetKeyCallback(this->windowPtr, genericCallback(keyPressed));
	glfwSetCursorPosCallback(this->windowPtr, genericCallback(mouseCallback));
}

void Window::CreateAndSetStandartCursor() {
	cursorPtr = glfwCreateStandardCursor(GLFW_HAND_CURSOR);
	glfwSetCursor(this->windowPtr, cursorPtr);
}

void Window::SubscribeOnEvents() {
	subscribeOnEventType(EV_KEYBOARD);
	subscribeOnEventType(EV_MOUSE);
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

void Window::processEvent(Event* event) {
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

void Window::processKeyboardEvent(KeyboardEvent* event) {
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

void Window::processMouseEvent(MouseEvent* event) {

	if (event == nullptr)
		return;

	//camera->ProcessMouseMovement(event->mouseState.xpos, event->mouseState.ypos);
}

void Window::Shutdown()
{
	glfwDestroyCursor(cursorPtr);
	glfwDestroyWindow(this->windowPtr);
	glfwTerminate();
}

void Window::Destroy() {
	Logger::Log("Shutdown window system", LOG_DEBUG);
	Shutdown();
}

