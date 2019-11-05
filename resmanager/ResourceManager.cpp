#include "ResourceManager.h"

#include <iostream>
#include <fstream>

using namespace Erbium;

void ResourceManager::Init() {
	imageLoader = new SOILImageLoader();
}

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

std::shared_ptr<Shader> ResourceManager::LoadShaderWithName(std::string name, std::string pathToVector, std::string pathToFragment)
{
	std::string vectorShaderSource = loadText(pathToVector);
	std::string fragmentShaderSource = loadText(pathToFragment);

	if (!vectorShaderSource.empty() & !fragmentShaderSource.empty()) {
		std::shared_ptr<Shader> shader = std::make_shared<Shader>(vectorShaderSource.c_str(), fragmentShaderSource.c_str());
		shadersMap[name] = shader;
		return shader;
	}
	else {
		Logger::Log("ResourceManager::LoadText failed. PathToVector is " + pathToVector + " PathToFragment is " + pathToFragment, LOG_ERROR);
	}

	return nullptr;
}

std::shared_ptr<Texture2D> ResourceManager::LoadTextureWithName(std::string name, std::string path)
{
	std::shared_ptr<Image> image = imageLoader->LoadImage(path);
	if (image->data != nullptr) {
		std::shared_ptr<Texture2D> texture = std::make_shared<Texture2D>(image->width, image->height, image->data);
		texturesMap[name] = texture;
		SOIL_free_image_data(image->data);
		return texture;
	}
	else {
		Logger::Log("SOIL::Load path " + path + "failed", LOG_ERROR);
	}

	return nullptr;
}

std::shared_ptr<Sprite> ResourceManager::GenerateSpriteFromTextureWithShader(std::string spriteName, std::string textureName, std::string shaderName)
{
	std::shared_ptr<Sprite> sprite =  std::make_shared<Sprite>(shadersMap[shaderName], texturesMap[textureName]);

	spritesMap[spriteName] = sprite;

	return sprite;
}

void ResourceManager::ReleaseResources()
{

	shaders.clear();
	textures.clear();
	sprites.clear();

	shadersMap.clear();
	texturesMap.clear();
	spritesMap.clear();
}

void ResourceManager::Destroy()
{
	Logger::Log("Shutdown resource manager", LOG_DEBUG);
	ReleaseResources();
}
