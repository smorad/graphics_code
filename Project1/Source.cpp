#include <iostream>
#include "Display.h"
#include <glew/glew.h>
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Transform.h"

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
	Transform transform;

	float counter = 0.0f;

	while (!display.isClosed()) {
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		// Translate
		transform.GetPos().x = sinf(counter);

		// Rotate
		transform.GetRot().z = counter;

		// Scale
		float cosCounter = cosf(counter);
		transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));

		shader.Bind();
		// Added later
		texture.Bind(0);
		shader.Update(transform);

		mesh.Draw();

		display.Update();
		counter += 0.01f;
	}
	return 0;
}