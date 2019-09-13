#pragma once

#include <GL/glew.h>
#include <iostream>


class Shader
{
	enum ShaderType {
		VERTEX,
		GEOMETRY,
		FRAGMENT,
	};

	GLuint id;
	GLuint Compile(const char* source, ShaderType type);
	bool IsCompileSuccess(GLuint shader);

	

public:
	Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
	~Shader();


	void Bind();

};

