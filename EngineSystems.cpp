#include "EngineSystems.h"



EngineSystems::EngineSystems()
{

}

void EngineSystems::InitSystems()
{
	//TODO: Loading config file here

	settingsManager.LoadSettings();

#ifdef _DEBUG
	Logger::SetConsoleLog(true);
	Logger::Log("DEBUG MOD ACTIVE", LOG_INFO);
#endif

	Camera* mainCamera = new Camera();
	Window* window = new Window(mainCamera,
		settingsManager.windowSettings.width,
		settingsManager.windowSettings.height,
		settingsManager.windowSettings.title);

	InputManager* inputManager = new InputManager();
	ResourceManager* resourceManager = new ResourceManager();
	Renderer* renderer = new Renderer(mainCamera);

	glfwSetWindowUserPointer(window->GetWindowPointer(), inputManager);

	systems["camera"] = mainCamera;
	systems["window"] = window;
	systems["inputManager"] = inputManager;
	systems["resourceManager"] = resourceManager;
	systems["renderer"] = renderer;

	registerSystemsInEventManager();
}

System* EngineSystems::GetSystem(std::string&& name)
{
	if (systems[name] != nullptr) {
		return systems[name];
	}

	Logger::Log("System with name " + name + " is not exists", LOG_ERROR);
}

void EngineSystems::UpdateSystems()
{
}

void EngineSystems::registerSystemsInEventManager()
{
	for (auto system : systems) {
		Logger::Log("Register " + system.first + " system", LOG_DEBUG);
		EventManager::AddSystem(system.second);
	}
}

void EngineSystems::TerminateSystems()
{
	
	for (auto system : systems) {
		Logger::Log("Terminating " + system.first + " system", LOG_DEBUG);
		system.second->Destroy();
	}
}
