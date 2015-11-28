#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include "shaders/shader.h"
using std::cout;
using std::endl;

#define WIDTH 800
#define HEIGHT 600

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	switch (key)
	{
	case GLFW_KEY_ESCAPE:
		switch (action)
		{
		case GLFW_PRESS:
			glfwSetWindowShouldClose(window, GL_TRUE);
			break;
		}
		break;
	}
}

int main(int argc, char* argv[])
{
	//Initialization

	if (glfwInit() == GL_FALSE)
	{
		cout << "glfwInit() failed" << endl;
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Hello, world!", nullptr, nullptr);
	if (!window)
	{
		cout << "glfwCreateWindow() failed" << endl;
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(window, &key_callback);
	glfwMakeContextCurrent(window);


	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		cout << "glewInit() failed" << endl;
		glfwTerminate();
		return -1;
	}

	glViewport(0, 0, WIDTH, HEIGHT);

	std::vector<float> color{ 0.2f, 0.3f, 0.3f, 1.0f }; //Background color
	
	//Vertices of two triangle (rectangle)
	std::vector<GLfloat> vertices
	{
		0.5f,  0.5f, 0.0f,  // Top Right
		0.5f, -0.5f, 0.0f,  // Bottom Right
		-0.5f,  0.5f, 0.0f,  // Top Left 
	};

	std::vector<GLfloat> vertices2
	{
		-0.5f,  0.5f, 0.0f,  // Top Left 
		0.5f, -0.5f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f,  // Bottom Left
	};

	//Indices of the rectangle
	std::vector<GLuint> indices
	{
		0, 1, 3,
		0, 3, 2
	};

	
	GLuint VAO1, VAO2, VBO, VBO2, EBO; 
	glGenVertexArrays(1, &VAO1);
	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &VBO2);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);

	//Specifies how OpenGL should interpret the vertex buffer data whenever a drawing call is made.
	//The interpretation specified is stored in the currently bound Vertex Array Object
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

	glEnableVertexAttribArray(0); //We activate the vertex attribute at location 0 (layout (location = 0). These are disabled by default.
	
	//A VAO stores the glBindBuffer calls when the target is GL_ELEMENT_ARRAY_BUFFER. 
	// This also means it stores its unbind calls so make sure you don't unbind the element array buffer before unbinding your VAO, 
	// otherwise it doesn't have an EBO configured.
	glBindVertexArray(0); //Unbind the VAO

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(VAO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);

	glBufferData(GL_ARRAY_BUFFER, vertices2.size() * sizeof(GLfloat), &vertices2[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	Shader shader("C:\\Users\\torre\\Documents\\visual studio 2015\\Projects\\LearnOpenGL\\LearnOpenGL\\shaders\\vertexshader.vert",
		"C:\\Users\\torre\\Documents\\visual studio 2015\\Projects\\LearnOpenGL\\LearnOpenGL\\shaders\\fragmentshader.frag");

	while (!glfwWindowShouldClose(window))
	{
		glClearBufferfv(GL_COLOR, 0, &color[0]);

		glUseProgram(shader.Program());

		glBindVertexArray(VAO1); //Bind the VAO to draw.
		glDrawArrays(GL_TRIANGLES, 0, 3);
		
		glBindVertexArray(VAO2);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		glfwPollEvents();
		glfwSwapBuffers(window);
		
		glBindVertexArray(0);
		glUseProgram(0);
	}

	glfwTerminate();
	return 0;
}

