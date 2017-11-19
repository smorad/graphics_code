#include "Mesh.h"
#include <glm/glm.hpp>
#include <fstream>
#include <string>

Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
	m_drawCount = numVertices;
	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject);

	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> textCoords;

	positions.reserve(numVertices);
	positions.reserve(numVertices);

	for (unsigned int i = 0; i < numVertices; i++) {
		positions.push_back(*vertices[i].GetPos());
		textCoords.push_back(*vertices[i].GetTextCoord());
	}

	// Move data onto GPU
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);


	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXTCOORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(positions[0]), &textCoords[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);


	// Unbind array
	glBindVertexArray(0);
	glBindVertexArray(1);

}
/*
std::vector<Vertex> Mesh::LoadObj(std::string filename) {
	std::vector<Vertex> vertices;
	std::ifstream file(filename);
	std::string str;
	float x, y, z;
	float r, g, b;

	while (file >> str >> x >> y >> z >> r >> g >> b) {
		vertices.push_back(glm::vec3(x, y, z));
	}
	return vertices;
}
*/

void Mesh::Draw() {
	glBindVertexArray(m_vertexArrayObject);

	glDrawArrays(GL_TRIANGLES, 0, m_drawCount);

	glBindVertexArray(0);

}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertexArrayObject);

}
