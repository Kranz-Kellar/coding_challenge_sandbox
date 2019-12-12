#include "SOILImageLoader.h"

using namespace Erbium;

std::shared_ptr<Image> SOILImageLoader::LoadImage(std::string path)
{
	std::shared_ptr<Image> image = std::make_shared<Image>();
	image->data = SOIL_load_image(path.c_str(), &image->width, &image->height, 0, SOIL_LOAD_RGBA);

	return image;
}
