#pragma once
#include <string>
#include <memory>


struct Image {
	int width;
	int height;
	unsigned char* data;
};

class ImageLoader
{
public:
	std::shared_ptr<Image> virtual LoadImage(std::string path) = 0;
	virtual ~ImageLoader() {};
};

