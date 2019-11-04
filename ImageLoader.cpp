#include "ImageLoader.h"

Image ImageLoader::LoadImage(std::string path) {
	Image image;
	image.data = SOIL_load_image(path.c_str(), &image.width, &image.height, 0, SOIL_LOAD_RGB);
	return image;
}