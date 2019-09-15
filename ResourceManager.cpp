#include "ResourceManager.h"

#include <iostream>
#include <fstream>

std::string ResourceManager::loadText(std::string path)
{
	
	std::ifstream file(path);
	if (file) {
		file.seekg(0, std::ios::end);
		size_t len = file.tellg();
		file.seekg(0);
		std::string text(len + 1, '\0');
		file.read(&text[0], len);

		return text;
	}

	return std::string();
}

Shader* ResourceManager::LoadShader(std::string pathToVector, std::string pathToFragment)
{

	std::string vectorShaderSource = loadText(pathToVector);
	std::string fragmentShaderSource = loadText(pathToFragment);

	if (!vectorShaderSource.empty() & !fragmentShaderSource.empty()) {
		Shader* shader = new Shader(vectorShaderSource.c_str(), fragmentShaderSource.c_str());
		shaders.push_back(shader);
		return shader;
	}
	else {
		std::cout << "LoadText::ERROR" << std::endl;
	}

	return nullptr;
}
