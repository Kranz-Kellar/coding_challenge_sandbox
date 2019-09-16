#pragma once

#include <vector>
#include <SOIL/SOIL.h>

#include "Shader.h"
#include "Texture2D.h"

class ResourceManager
{
	 std::vector<Shader*> shaders;
	 std::vector<Texture2D*> textures;
	
	
	 std::string loadText(std::string path);
public:

	 
	 Shader* LoadShader(std::string pathToVector, std::string pathToFragment);
	 Texture2D* LoadTexture(std::string path);

	 void ReleaseResources();
};

