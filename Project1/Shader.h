#pragma once

#include<string>
#include <glew/glew.h>
#include "Transform.h"

class Shader
{
public:
	Shader(const std::string& fileName);
	void Bind();
	// Update all uniforms (transform)
	void Update(const Transform& transform);
	~Shader();

private:
	static const unsigned int NUM_SHADERS = 2;

	enum {
		TRANSFORM_U,

		NUM_UNIFORMS
	};

	// Shader program
	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];

};

