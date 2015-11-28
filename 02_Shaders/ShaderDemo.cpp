#include "ShaderDemo.h"
#include <glm/glm.hpp>

ShaderDemo::ShaderDemo(std::string name, int width, int height)
	: Application(name, width, height)
{}

void ShaderDemo::Run()
{
	GLuint VAO, VBO;
	std::vector<float> color{ 0.2f, 0.3f, 0.3f, 1.0f }; //Background color
	std::vector<GLfloat> vertices
	{
		//Positions				//Colors
		0.0f,  0.5f, 0.0f,		1.0f, 0.0f, 0.0f,	// Top Center
		0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,	// Bottom Right
		-0.5f,  -0.5f, 0.0f,	0.0f, 0.0f, 1.0f	// Bottom Left
	};

	//Generate buffers
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO); //Bind VAO

	//Bind VBO and populate it with data
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0); //Positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat))); //Colors
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	Shader shader("shaders\\vertexshader.vert", "shaders\\fragmentshader.frag");

	//Note that finding the uniform location does not require you to use the shader program first, but updating a uniform does require you to first use the program (by calling glUseProgram),
	// because it sets the uniform on the currently active shader program.
	//GLint vertexColorLocation = glGetUniformLocation(shader.Program(), "vertexColor"); //Get the location of the uniform variable named "vertexColor"

	//if (vertexColorLocation == -1) //could not be found
	//{
	//	cout << "glGetUniformLocation() couldn't find variable" << endl;
	//}

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearBufferfv(GL_COLOR, 0, &color[0]);

		GLfloat timeValue = glfwGetTime();
		GLfloat greenValue = (sin(timeValue)/2) + 0.5;

		glUseProgram(shader.Program());
		//glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
		glBindVertexArray(VAO);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(0);
		glUseProgram(0);
		glfwSwapBuffers(window);
	}
}
