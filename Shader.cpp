#include "Shader.h"

#define INFO_LOG_SIZE 512


GLuint Shader::Compile(const char* source, ShaderType type)
{
	GLuint shaderId;
	switch (type) {
	case VERTEX:
		shaderId = glCreateShader(GL_VERTEX_SHADER);
		break;
	case GEOMETRY:
		shaderId = glCreateShader(GL_GEOMETRY_SHADER);
		break;
	case FRAGMENT:
		shaderId = glCreateShader(GL_FRAGMENT_SHADER);
		break;
	}

	glShaderSource(shaderId, 1, &source, NULL);
	glCompileShader(shaderId);
	
	return shaderId;
}

bool Shader::IsCompileSuccess(GLuint shader)
{
	GLint success;
	GLchar infoLog[INFO_LOG_SIZE];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader, INFO_LOG_SIZE, NULL, infoLog);
		std::cout << "ERROR::SHADER_COMPILE_FAILED::" << infoLog << std::endl;

		return false;
	}

	return true;
}

Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath)
{
		//Getting source code with resource manager
	const char* vertexShaderSource = vertexShaderPath;
	const char* fragmentShaderSource = fragmentShaderPath;

	GLuint vertexShader = Compile(vertexShaderSource, VERTEX);
	GLuint fragmentShader = Compile(fragmentShaderSource, FRAGMENT);

	IsCompileSuccess(vertexShader);
	IsCompileSuccess(fragmentShader);

	this->id = glCreateProgram();
	glAttachShader(this->id, vertexShader);
	glAttachShader(this->id, fragmentShader);
	glLinkProgram(this->id);

	GLint success;
	GLchar infoLog[INFO_LOG_SIZE];
	glGetProgramiv(this->id, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(this->id, INFO_LOG_SIZE, NULL, infoLog);
		std::cout << "ERROR::SHADER_LINK_FAILED::" << infoLog << std::endl;

	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	//glDeleteShader(geometryShader);
}


Shader::~Shader()
{
	glDeleteProgram(this->id);
}

void Shader::Bind()
{
	glUseProgram(this->id);
}