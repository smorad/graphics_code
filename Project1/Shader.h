#pragma once

#include<string>
#include <glew/glew.h>

class Shader
{
public:
	Shader(const std::string& fileName);
	void Bind();
	~Shader();

private:
	static const unsigned int NUM_SHADERS = 2;
	// Shader program
	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
};

