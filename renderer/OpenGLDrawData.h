#pragma once

#include "IDrawData.h"

namespace Erbium {

	struct OpenGLDrawData : IDrawData
	{
		glm::mat4 modelMatrix;
		GLuint typeOfDraw;
	};

}
