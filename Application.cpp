#include "Application.h"

void Application::Init()
{
#ifdef _DEBUG
	Logger::Log("DEBUG MOD ACTIVE", LOG_INFO);
#endif

	camera = new Camera();
	window = new Window(camera, 800, 600, "Boxel");
	window->subscribeOnEventType(EV_KEYBOARD);
	window->SetCursor(true);

	inputManager = new InputManager();
	glfwSetWindowUserPointer(window->GetWindowPointer(), inputManager);

	resourceManager = new ResourceManager();

	EventManager::AddSystem(inputManager);
	EventManager::AddSystem(window);

}

void Application::Shutdown()
{
	//window->Shutdown();
	//resourceManager->ReleaseResources();

	delete camera;
	delete window;
	delete resourceManager;
	delete inputManager;
}

void Application::Process()
{
	float time = 0.0f;
	float lastTime = 0.0f;
	delta = 0.0f;
	while (!window->windowShouldClose) {
		time = glfwGetTime();
		delta = time - lastTime;
		lastTime = time;


		EventManager::ProcessEvents();
		window->Update();

		//Updating game logic
		//Updating phys
		//Render picture

		window->SwapBuffers();
	}
}
