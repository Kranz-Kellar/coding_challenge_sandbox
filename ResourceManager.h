#pragma once

#include <vector>

#include "Shader.h"


class ResourceManager
{
	 std::vector<Shader*> shaders;
	
	
	 std::string loadText(std::string path);
public:

	 
	 Shader* LoadShader(std::string pathToVector, std::string pathToFragment);
};

