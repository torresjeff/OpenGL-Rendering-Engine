//GLEW
#include <GL/glew.h>
//GLFW
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
	if (glfwInit() == GL_FALSE)
	{
		cout << "glfwInit() failed" << endl;
		return -1;
	}
	
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Hello, world!", nullptr, nullptr);
	if (!window)
	{
		cout << "glfwCreateWindow() failed" << endl;
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(window, &key_callback);
	glfwMakeContextCurrent(window);


	/*
	 * Notice that we set the glewExperimental variable to GL_TRUE before initializing GLEW.
	 * Setting glewExperimental to true ensures GLEW uses more modern techniques for managing OpenGL functionality.
	 * Leaving it to its default value of GL_FALSE might give issues when using the core profile of OpenGL.
	 **/
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
		-0.5f, -0.5f, 0.0f,  // Bottom Left
	};

	//Indices of the rectangle
	std::vector<GLuint> indices
	{
		0, 1, 3,
		0, 3, 2
	};

	//VAO: vertex array object (stores various VBO objects and their settings/state/bindings). A VAO encases the entire vertex attrib state and bound vertex/index buffers.
	// VBO: vertex buffer object (contains vertex data and how to interpret each one),
	// EBO: element buffer object (for indexed drawing).
	GLuint VAO, VBO, EBO; 
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO); //From this point onward, the VAO will store calls made to glEnableVertexAttribArray or glDisableVertexAttribArray,
							// vertex attribute configurations via glVertexAttribPointer,
							// and vertex buffer objects (VBOs) associated with vertex attributes by calls to glVertexAttribPointer.
							// This makes it easy for us if we had 100 different objects. We would just bind the VAO of the associated object and all its configuration.
							// NOTE: also stores calls to GL_ELEMENT_ARRAY_BUFFEr (ebo)
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); //The VAO stores this call. The EBO only exists within a VAO.

	//After calling glBindBuffer, and binding a buffer to a specific target (eg. GL_ARRAY_BUFFER), any calls we make on that target
	// will modify the buffer that is currently bound to it (eg. VBO)

	//Copies the contents of "vertices" (3rd parameter) to the object that is currently bound to GL_ARRAY_BUFFER (eg. VBO)
	//GL_STATIC draw means the data in the buffer will not change. This doesn't mean we can't change the position in the shaders, only that the buffer itself will not change its data.
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);
	
	//Shader shader("../LearnOpenGL/shaders/vertextshader.vert", "../LearnOpenGL/shaders/fragmentshader.frag");
	

	//Specifies how OpenGL should interpret the vertex buffer data whenever a drawing call is made.
	//The interpretation specified is stored in the currently bound Vertex Array Object
	glVertexAttribPointer(0, //We're defining the data of vertex attribute #0, that is: layout (location = 0)
		3, //Each vertex consists of 3 components (x, y, and z), if we had position + color, we would specify 6 (x, y, z, r, g, b)
		GL_FLOAT, //The type of each component is a GL_FLOAT
		GL_FALSE, //Do not normalize the data
		3 * sizeof(GLfloat), //Stride: tells us the space between consecutive vertex attribute sets (eg. how far away in bytes, is one position from the next position, or a color from the next color).
							// Since the next set of position data is located exactly 3 times the size of a GLfloat away we specify that value as the stride.
							// Note that since we know that the array is tightly packed (there is no space between the next vertex attribute value) we could've also specified the stride as 0 
							// to let OpenGL determine the stride (this only works when values are tightly packed).
							// NOTE: again, if we had position + color in the order: x, y, z, r, g, b; that would mean the stride would be 6 * sizeof(GLfloat).
							// We count how far away is one set of information from another of the same type (position would be 6 * sizeof(GLfloat) bytes away from another position)
		(GLvoid*)0); //This is the offset of where the position data begins in the buffer. Since the position data is at the start of the data array this value is just 0.
					//If we had position + color (in the order x, y, z, r, g, b), the position attribute would still be offset 0, but the color attribute would start from 3 * sizeof(GLfloat)
					//Because the color attribute is not at the beginning of the array, instead it starts from the 12th byte.
	//NOTE: Each vertex attribute takes its data from memory managed by a VBO and which VBO it takes its data from (one could have multiple VBOs) is determined by the VBO currently bound
	// to GL_ARRAY_BUFFER when calling glVertexAttribPointer.
	glEnableVertexAttribArray(0); //We activate the vertex attribute at location 0 (layout (location = 0). These are disabled by default.
	
	//A VAO stores the glBindBuffer calls when the target is GL_ELEMENT_ARRAY_BUFFER. 
	// This also means it stores its unbind calls so make sure you don't unbind the element array buffer before unbinding your VAO, 
	// otherwise it doesn't have an EBO configured.
	glBindVertexArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	

	//Shader shader("C:\\Users\\torre\\Documents\\visual studio 2015\\Projects\\LearnOpenGL\\LearnOpenGL\\shaders\\vertexshader.vert",
		//"C:\\Users\\torre\\Documents\\visual studio 2015\\Projects\\LearnOpenGL\\LearnOpenGL\\shaders\\fragmentshader.frag");

	Shader shader("..\\LearnOpenGl\\shaders\\vertexshader.vert", "..\\LearnOpenGl\\shaders\\fragmentshader.frag");

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glClearBufferfv(GL_COLOR, 0, &color[0]);

		glUseProgram(shader.Program());

		glBindVertexArray(VAO); //Bind the VAO to draw.
		
		//Use indexed drawing (makes us of the EBO)
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		glBindVertexArray(0);
		glUseProgram(0);

		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}