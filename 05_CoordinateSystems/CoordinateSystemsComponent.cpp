#include "CoordinateSystemsComponent.h"
#include <SOIL/SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "CoordinateSystemsComponent.h"

CoordinateSystemsComponent::CoordinateSystemsComponent()
	: DrawableGameComponent()
{}

CoordinateSystemsComponent::CoordinateSystemsComponent(Application & application)
	: DrawableGameComponent(application)
{}

void CoordinateSystemsComponent::Initialize()
{}

void CoordinateSystemsComponent::Draw(float DeltaSeconds)
{
	GLuint VAO, VBO, EBO;
	int imageWidth, imageHeight, imageWidth2, imageHeight2;

	std::vector<GLfloat> color{ 0.2f, 0.3f, 0.3f, 1.0f }; //Background color

	std::vector<GLfloat> vertices =
	{
		//FRONT FACE
		//Positions				//Texture Coords.
		0.5f,  0.5f, 0.5f,		 1.0f, 1.0f,   // Top Right = 0
		0.5f, -0.5f, 0.5f,		 1.0f, 0.0f,   // Bottom Right = 1
		-0.5f, -0.5f, 0.5f,		 0.0f, 0.0f,   // Bottom Left = 2
		0.5f,  0.5f, 0.5f,		 1.0f, 1.0f,   // Top Right = 0
		-0.5f, -0.5f, 0.5f,		 0.0f, 0.0f,   // Bottom Left = 2
		-0.5f,  0.5f, 0.5f,		 0.0f, 1.0f,    // Top Left = 3

												//BACK FACE
		0.5f,  0.5f, -0.5f,		 1.0f, 1.0f,   // Top Right = 0
		0.5f, -0.5f, -0.5f,		 1.0f, 0.0f,   // Bottom Right = 1
		-0.5f, -0.5f, -0.5f,	 0.0f, 0.0f,   // Bottom Left = 2
		0.5f,  0.5f, -0.5f,		 1.0f, 1.0f,   // Top Right = 0
		-0.5f, -0.5f, -0.5f,	 0.0f, 0.0f,   // Bottom Left = 2
		-0.5f,  0.5f, -0.5f,	 0.0f, 1.0f,    // Top Left = 3

												//RIGHT FACE
		0.5f,  0.5f, -0.5f,		 1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,		 1.0f, 0.0f,
		0.5f, -0.5f, 0.5f,		 0.0f, 0.0f,
		0.5f,  0.5f, -0.5f,		 1.0f, 1.0f,
		0.5f, -0.5f, 0.5f,		 0.0f, 0.0f,
		0.5f,  0.5f, 0.5f,		 0.0f, 1.0f,

		//LEFT FACE
		-0.5f,  0.5f, -0.5f,	 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f,		 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	 1.0f, 1.0f,
		-0.5f, -0.5f, 0.5f,		 0.0f, 0.0f,
		-0.5f,  0.5f, 0.5f,		 0.0f, 1.0f,

		//TOP FACE
		0.5f,  0.5f, -0.5f,		 1.0f, 1.0f,
		0.5f,  0.5f, 0.5f,		 1.0f, 0.0f,
		-0.5f,  0.5f, 0.5f,		 0.0f, 0.0f,
		0.5f,  0.5f, -0.5f,		 1.0f, 1.0f,
		-0.5f,  0.5f, 0.5f,		 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	 0.0f, 1.0f,

		//BOTTOM FACE
		0.5f,  -0.5f, -0.5f,	 1.0f, 1.0f,
		0.5f,  -0.5f, 0.5f,		 1.0f, 0.0f,
		-0.5f,  -0.5f, 0.5f,	 0.0f, 0.0f,
		0.5f,  -0.5f, -0.5f,	 1.0f, 1.0f,
		-0.5f, -0.5f, 0.5f,		 0.0f, 0.0f,
		-0.5f,  -0.5f, -0.5f,	 0.0f, 1.0f
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	Shader shader("shaders/vertexshader.vert", "shaders/fragmentshader.frag");

	//---------- TEXTURE ----------//
	GLuint texture1, texture2;

	glGenTextures(1, &texture1);
	glGenTextures(1, &texture2);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture1); //Bind it, so subsequent texture commands will configure the currently bound texture.
	glUniform1i(glGetUniformLocation(shader.Program(), "ourTexture"), 0); //Set the location of the uniform "ourTexture" to location 0, so it corresponds with GL_TEXTURE0 (active texture-unit).

																		  // Set the texture wrapping parameters (when specifying texture coordinates out of the [0,1] range).
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//Set parameters when downscaling/minifying (MIN_FILTER) and upscaling/magnifying (MAG_FILTER)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); //GL_LINEAR_MIPMAP_LINEAR: linearly interpolates between the two closest mipmaps and samples the texture via linear interpolation.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //There's no point in using mipmaps for magnifying (mipmaps are usually used for downscaling) so we don't specify a mipmap filtering option.


																	  //Load the container image and store it as a raw byte array
	unsigned char* image = SOIL_load_image("res/container.jpg", &imageWidth, &imageHeight, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glUniform1i(glGetUniformLocation(shader.Program(), "ourTexture2"), 1);


	unsigned char* image2 = SOIL_load_image("res/awesomeface.png", &imageWidth2, &imageHeight2, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth2, imageHeight2, 0, GL_RGB, GL_UNSIGNED_BYTE, image2);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image2);
	glBindTexture(GL_TEXTURE_2D, 0);


		//Model matrix = modelToWorld; View matrix = worldToView; projection = Projection Matrix -> ortho/perspective
		glm::mat4 modelToWorld, worldToview, projection;
		modelToWorld = glm::rotate(modelToWorld, glm::radians((GLfloat)glfwGetTime() * 50.0f), glm::vec3(0.5f, 1.0f, 0.0f)); //Rotate -55 degress on the X axis

																															 //Since we want it to look like we're moving the camera backwards (positive Z axis), we instead move the entire scene foreward (negative Z axis)
		worldToview = glm::translate(worldToview, glm::vec3(0.0f, 0.0f, -3.0f));

		projection = glm::perspective(glm::radians(90.0f), (float)mApplication->GetWidth()/(float)mApplication->GetHeight(), 0.1f, 100.0f);
		glClear(GL_DEPTH_BUFFER_BIT);
		glClearBufferfv(GL_COLOR, 0, &color[0]);
		glUseProgram(shader.Program());

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1); //Bind it, so subsequent texture commands will configure the currently bound texture.
		glUniform1i(glGetUniformLocation(shader.Program(), "ourTexture"), 0); //Set the location of the uniform "ourTexture" to location 0, so it corresponds with GL_TEXTURE0 (active texture-unit).

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2); //Automatically assigns the texture to the fragment shader's sampler (no need to get uniform location, etc.)
		glUniform1i(glGetUniformLocation(shader.Program(), "ourTexture2"), 1); //Set the location of the uniform "ourTexture2" to location 1, so it corresponds with GL_TEXTURE1 (active texture-unit).


		glm::vec3 cubePositions[] =
		{
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(2.0f, 5.0f, -15.0f),
			glm::vec3(-1.5f, -2.2f, -2.5f),
			glm::vec3(-3.8f, -2.0f, -12.3f),
			glm::vec3(2.4f, -0.4f, -3.5f),
			glm::vec3(-1.7f, 3.0f, -7.5f),
			glm::vec3(1.3f, -2.0f, -2.5f),
			glm::vec3(1.5f, 2.0f, -2.5f),
			glm::vec3(1.5f, 0.2f, -1.5f),
			glm::vec3(-1.3f, 1.0f, -1.5f)
		};

		GLuint viewLocation = glGetUniformLocation(shader.Program(), "view");
		glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(worldToview));
		GLuint projectionLocation = glGetUniformLocation(shader.Program(), "projection");
		glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));

		glBindVertexArray(VAO);

		for (int i = 0; i < 10; ++i)
		{
			glm::mat4 cubesWorldSpace;
			cubesWorldSpace = glm::translate(cubesWorldSpace, cubePositions[i]);
			cubesWorldSpace = glm::rotate(cubesWorldSpace, glm::radians((float)20 * (i + 1) * (float)glfwGetTime()), glm::vec3(1.0f, 0.3f, 0.5f));
			GLuint modelLocation = glGetUniformLocation(shader.Program(), "model");
			glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(cubesWorldSpace));

			glDrawArrays(GL_TRIANGLES, 0, 36);

		}

		glBindVertexArray(0);
		glUseProgram(0);
	
}

