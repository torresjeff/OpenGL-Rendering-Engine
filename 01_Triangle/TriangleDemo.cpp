#include "TriangleDemo.h"

TriangleDemo::TriangleDemo(std::string name, int width, int height)
	: Application(name, width, height)
{}

void TriangleDemo::Run()
{
	std::vector<float> color{ 1.0f, 0.3f, 0.5f, 1.0f }; //Background color

	Shader shader("..\\01_Triangle\\shaders\\vertexshader.vert", "..\\01_Triangle\\shaders\\fragmentshader.frag");

	//Vertices of two triangle (rectangle)
	std::vector<GLfloat> vertices
	{
		0.5f,  0.5f, 0.0f,  // Top Right
		0.5f, -0.5f, 0.0f,  // Bottom Right
		-0.5f,  0.5f, 0.0f,  // Top Left
		-0.5, -0.5f, 0.0f
	};

	//Indices of the rectangle
	std::vector<GLuint> indices
	{
		0, 1, 3,
		0, 3, 2
	};


	GLuint VAO, VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO); //Bind VAO

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
	
	//Specifies how OpenGL should interpret the vertex buffer data whenever a drawing call is made.
	//The interpretation specified is stored in the currently bound Vertex Array Object
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0); //We activate the vertex attribute at location 0 (layout (location = 0). These are disabled by default.

	//A VAO stores the glBindBuffer calls when the target is GL_ELEMENT_ARRAY_BUFFER.
	// This also means it stores its unbind calls so make sure you don't unbind the element array buffer before unbinding your VAO,
	// otherwise it doesn't have an EBO configured.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);

	glBindVertexArray(0); //Unbind VAO

	while (!glfwWindowShouldClose(window))
	{
		glClearBufferfv(GL_COLOR, 0, &color[0]);
		glUseProgram(shader.Program());
		glBindVertexArray(VAO); //Bind the VAO to draw.
		
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);

		glfwPollEvents();
		glfwSwapBuffers(window);

		glBindVertexArray(0);
		glUseProgram(0);
	}
}
