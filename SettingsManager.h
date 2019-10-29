#pragma once

#include <iostream>
#include "FileIO.h"
#include <pugi/pugixml.hpp>

#include "Logger.h"

using namespace pugi;

struct WindowSettings {
	unsigned int width;
	unsigned int height;
	const char* title;
};

struct ResourceManagerSettings {
	std::string pathToResources;
};


class SettingsManager
{
	const char* pathToConfigFile = "config.xml";
	pugi::xml_document settingsDocument;
	pugi::xml_parse_result settingsTree;

public:

	WindowSettings windowSettings;
	ResourceManagerSettings resManagerSettings;

	void LoadSettings() {
		settingsTree = settingsDocument.load_file(pathToConfigFile);
		if (!settingsTree) {
			Logger::Log("Config file not found", LOG_ERROR);
			return;
		}

		xml_node windowSettingsNode = settingsDocument.child("Settings").child("WindowSettings");
		windowSettings.title = windowSettingsNode.child("Title").attribute("Value").as_string();
		windowSettings.width = windowSettingsNode.child("Width").attribute("Value").as_uint();
		windowSettings.height = windowSettingsNode.child("Height").attribute("Value").as_uint();

		xml_node resourceManagerNode = settingsDocument.child("Settings").child("ResourceManagerSettings");
		resManagerSettings.pathToResources = resourceManagerNode.child("PathToResources").attribute("Value").as_string();

	}
};

