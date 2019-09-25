#pragma once

#include <iostream>
#include "FileIO.h"

struct WindowSettings {
	unsigned int width;
	unsigned int height;
	const char* title;
};



class SettingsManager
{
public:
	WindowSettings winSettings;

	static void LoadSettings(std::string pathToSettingsFile) {
		std::string settings = FileIO::ReadFile(pathToSettingsFile);
	}
};

