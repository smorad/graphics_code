#pragma once

#include <string>
#include <glew\glew.h>


class Texture
{
public:
	Texture(const std::string& fileName);
	void Bind(unsigned int unit);
	~Texture();
private:
	GLuint m_texture;
};

