#pragma once

#include <GL/glew.h>
#include "Shader.h"
#include <glm/glm.hpp>
#include "Texture2D.h"
#include "Camera.h"

class Renderer
{

	GLuint VAO, VBO, IBO;

	glm::mat4 projection;
	Camera* camera;

	void Init();
public:
	Renderer(Camera* camera);

	void drawObject(std::shared_ptr<Shader> shader, glm::mat4 model);

};

