#pragma once

#include <vector>
#include <map>
#include <SOIL/SOIL.h>

#include "../System.h"

#include "../Logger.h"
#include "../Shader.h"
#include "../Texture2D.h"
#include "../Sandbox/Sprite.h"

#include "ImageLoader.h"
#include "SOILImageLoader.h"

namespace Erbium {


	class ResourceManager : public Module
	{
		ImageLoader* imageLoader;

		std::vector<std::shared_ptr<Shader>> shaders;
		std::vector<std::shared_ptr<Texture2D>> textures;
		std::vector<std::shared_ptr<Sprite>> sprites;

		std::map<std::string, std::shared_ptr<Shader>> shadersMap;
		std::map<std::string, std::shared_ptr<Texture2D>> texturesMap;
		std::map<std::string, std::shared_ptr<Sprite>> spritesMap;

		std::string loadText(std::string path);

		//resPack loadResourcePackage(std::string path);

		void ReleaseResources();
	public:
		void Init();

		std::shared_ptr<Texture2D> LoadTextureWithName(std::string name, std::string path);
		std::shared_ptr<Shader> LoadShaderWithName(std::string name, std::string pathToVector, std::string pathToFragment);
		std::shared_ptr<Sprite> GenerateSpriteFromTextureWithShader(std::string spriteName, std::string textureName, std::string shaderName);



		void Destroy();
	};

}
