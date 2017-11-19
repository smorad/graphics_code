#include <iostream>
#include "Display.h"
#include <glew/glew.h>
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

int main(int argc, char** argv) {
	Display display(800, 600, "test");


	Vertex vertices[] = { 
		Vertex(glm::vec3(-0.5,-0.5,0), glm::vec2(0,0)), 
		Vertex(glm::vec3(0,0.5,0), glm::vec2(0.5,1.0)),
		Vertex(glm::vec3(0.5,-0.5,0), glm::vec2(1.0, 0.0))
	};

	Shader shader("./res/basicShader");
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Texture texture("./res/asteroid.jpg");

	while (!display.isClosed()) {
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		shader.Bind();
		mesh.Draw();

		display.Update();
	}
	return 0;
}