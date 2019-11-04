#pragma once
#include <string>
#include <SOIL/SOIL.h>

struct Image {
	int width;
	int height;
	unsigned char* data;
};

class ImageLoader
{
public:
	Image LoadImage(std::string path);


};

