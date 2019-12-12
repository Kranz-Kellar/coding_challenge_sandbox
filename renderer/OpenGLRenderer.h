#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "IRenderer.h"
#include "OpenGLDrawData.h"

#include "..//Camera.h"
#include "..//Logger.h"
#define RIGHT_BOTTOM -0.5f, 0.5f, 0.0f
#define LEFT_BOTTOM -0.5f,-0.5f, 0.0f
#define RIGHT_TOP 0.5f, 0.5f, 0.0f
#define LEFT_TOP  0.5f,-0.5f, 0.0f

namespace Erbium {

	class OpenGLRenderer : public IRenderer
	{
		Camera* viewCamera;

		GLuint StaticDrawVAO;
		GLuint DynamicDrawVAO;
		GLuint StreamDrawVAO;

		glm::mat4 projection;

		void InitStaticBuffer();
		void InitDynamicBuffer();
		void InitStreamBuffer();
		void SetBufferOfType(GLuint type) const;
	public:
		OpenGLRenderer(Camera* camera);

		void setCamera(Camera* camera);
		void Draw2DObject(IDrawData* drawData) override;
	};

}