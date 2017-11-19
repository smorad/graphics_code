#pragma once
#include <glew/glew.h>
#include <glm/glm.hpp>
#include <vector>

class Vertex {
public:
	Vertex(const glm::vec3& pos, const glm::vec2& textCoord) {
		this->pos = pos;
		this->textCoord = textCoord;
	}

	inline glm::vec3* GetPos() {
		return &pos;
	}

	glm::vec2* GetTextCoord() {
		return &textCoord;
	}
private:
	glm::vec3 pos;
	glm::vec2 textCoord;

};


class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices);
	//std::vector<Vertex> LoadObj(std::string filename);
	void Draw();
	~Mesh();
private:

	enum {
		POSITION_VB,
		TEXTCOORD_VB,
		NUM_BUFFERS
	};
	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;
};

