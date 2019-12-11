#pragma once

#include <string>
#include <map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "System.h"

#include "Logger.h"

#include "EventManager.h"
#include "InputManager.h"
#include "resmanager/ResourceManager.h"
#include "SettingsManager.h"

#include "renderer/IRenderer.h"
#include "renderer/OpenGLRenderer.h"
#include "Window.h"
#include "Camera.h"

//Sounds system
//Phys system
//Other systems

namespace Erbium {

	class EngineSystems
	{
		SettingsManager settingsManager;
		std::map<std::string, Module*> systems;
		void registerSystemsInEventManager();
	public:
		EngineSystems();
		void InitSystems();
		Module* GetSystem(std::string&& name);
		void UpdateSystems();
		void TerminateSystems();
	};

}
