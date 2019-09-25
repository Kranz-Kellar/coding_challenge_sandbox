#pragma once

#include "Logger.h"
#include "Window.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "EventManager.h"

class Application
{
	Camera* camera;
	Window* window;
	InputManager* inputManager;
	ResourceManager* resourceManager;

	float delta;
public:
	Application();
	~Application();

	void Init();
	void Shutdown();


	void Process();
};


