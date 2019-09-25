#pragma once

#include <vector>
#include <map>
#include <SOIL/SOIL.h>

#include "Logger.h"
#include "Shader.h"
#include "Texture2D.h"
#include "Sandbox/Sprite.h"



/*
 TODO: Хранение шейдеров, текстур, спрайтов и прочих ресурсов в хеш-таблицах
*/

class ResourceManager
{
	 std::vector<std::shared_ptr<Shader>> shaders;
	 std::vector<std::shared_ptr<Texture2D>> textures;
	 std::vector<std::shared_ptr<Sprite>> sprites;

	 std::map<std::string, std::shared_ptr<Shader>> shadersMap;
	 std::map<std::string, std::shared_ptr<Texture2D>> texturesMap;
	 std::map<std::string, std::shared_ptr<Sprite>> spritesMap;
	
	 std::string loadText(std::string path);
public:

	 
	 std::shared_ptr<Shader> LoadShader(std::string pathToVector, std::string pathToFragment);
	 std::shared_ptr<Shader> LoadShaderWithName(std::string name, std::string pathToVector, std::string pathToFragment);
	 std::shared_ptr<Texture2D> LoadTexture(std::string path);
	 std::shared_ptr<Texture2D> LoadTextureWithName(std::string name, std::string path);

	 //Заглушка для последующего апгрейда с хеш-таблицами
	 std::shared_ptr<Sprite> GenerateSpriteFromTextureWithShader(std::string spriteName, std::string textureName, std::string shaderName);

	 void ReleaseResources();
};

