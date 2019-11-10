#pragma once

#include "IDrawData.h"

struct OpenGLDrawData : IDrawData
{
	glm::mat4 modelMatrix;
	GLuint typeOfDraw;
};

