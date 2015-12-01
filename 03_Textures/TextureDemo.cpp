#include "TextureDemo.h"
#include <SOIL/SOIL.h>
#include "InputHandler.h"

TextureDemo::TextureDemo(std::string name, int width, int height)
	: Application(name, width, height)
{}

GLfloat interpolation = .5f;

void TextureDemo::Run()
{
	glfwSetKeyCallback(window, TextureDemoCallback);
	GLuint VAO, VBO, EBO;
	int imageWidth, imageHeight, imageWidth2, imageHeight2;

	std::vector<GLfloat> color{ 0.2f, 0.3f, 0.3f, 1.0f }; //Background color

	std::vector<GLfloat> vertices =
	{
		// Positions          // Colors           // Texture Coords. When we specify texture coords. out of the [0, 1] range, OpenGL repeats the texture by default.
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   2.0f, 2.0f,   // Top Right = 0
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   2.0f, 0.0f,   // Bottom Right = 1
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // Bottom Left = 2
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 2.0f    // Top Left = 3
	};

	//Indices of the rectangle
	std::vector<GLuint> indices
	{
		0, 1, 2,
		0, 2, 3
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	//glBindVertexArray(0);

	Shader shader("shaders/vertexshader.vert", "shaders/fragmentshader.frag");

	//---------- TEXTURE ----------//
	GLuint texture1, texture2;

	glGenTextures(1, &texture1);
	glGenTextures(1, &texture2);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture1); //Bind it, so subsequent texture commands will configure the currently bound texture.
	glUniform1i(glGetUniformLocation(shader.Program(), "ourTexture"), 0); //Set the location of the uniform "ourTexture" to location 0, so it corresponds with GL_TEXTURE0 (active texture-unit).

	// Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

	//Set parameters when downscaling/minifying (MIN_FILTER) and upscaling/magnifying (MAG_FILTER)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); //GL_LINEAR_MIPMAP_LINEAR: linearly interpolates between the two closest mipmaps and samples the texture via linear interpolation.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //There's no point in using mipmaps for magnifying (mipmaps are usually used for downscaling) so we don't specify a mipmap filtering option.


	//Load the container image and store it as a raw byte array
	unsigned char* image = SOIL_load_image("res/container.jpg", &imageWidth, &imageHeight, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image); // Populate the texture with data and specify the format to store it and the format it is given in.

	glGenerateMipmap(GL_TEXTURE_2D); // Automatically generates required mipmaps for the texture
	SOIL_free_image_data(image); // Free image memory
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glUniform1i(glGetUniformLocation(shader.Program(), "ourTexture2"), 1); //Set the location of the uniform "ourTexture2" to location 1, so it corresponds with GL_TEXTURE1 (active texture-unit).
	
	//Load the awesomeface image and store it as a raw byte array
	unsigned char* image2 = SOIL_load_image("res/awesomeface.png", &imageWidth2, &imageHeight2, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth2, imageHeight2, 0, GL_RGB, GL_UNSIGNED_BYTE, image2);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image2);
	glBindTexture(GL_TEXTURE_2D, 0);

	glUniform1f(glGetUniformLocation(shader.Program(), "interpolation"), 1.0f);
	

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearBufferfv(GL_COLOR, 0, &color[0]);
		glUseProgram(shader.Program());
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1); //Bind it, so subsequent texture commands will configure the currently bound texture.
		glUniform1i(glGetUniformLocation(shader.Program(), "ourTexture"), 0); //Set the location of the uniform "ourTexture" to location 0, so it corresponds with GL_TEXTURE0 (active texture-unit).

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2); //Automatically assigns the texture to the fragment shader's sampler (no need to get uniform location, etc.)
		glUniform1i(glGetUniformLocation(shader.Program(), "ourTexture2"), 1); //Set the location of the uniform "ourTexture2" to location 1, so it corresponds with GL_TEXTURE1 (active texture-unit).

		glUniform1f(glGetUniformLocation(shader.Program(), "interpolation"), interpolation);

		glBindVertexArray(VAO);

		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);

		glBindVertexArray(0);
		glUseProgram(0);
		glfwSwapBuffers(window);
	}

}
