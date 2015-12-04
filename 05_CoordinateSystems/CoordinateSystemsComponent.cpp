#include "CoordinateSystemsComponent.h"
#include <SOIL/SOIL.h>
#include "CoordinateSystemsComponent.h"

CoordinateSystemsComponent::CoordinateSystemsComponent()
	: DrawableGameComponent()
{}

CoordinateSystemsComponent::CoordinateSystemsComponent(Application & application)
	: DrawableGameComponent(application)
{}

void CoordinateSystemsComponent::Initialize()
{
	std::vector<GLfloat> color{ 0.2f, 0.3f, 0.3f, 1.0f }; //Background color

	mVertices =
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

	mCubePositions =
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

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(GLfloat), &mVertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
	
	mShader = Shader("shaders/vertexshader.vert", "shaders/fragmentshader.frag");

	//---------- TEXTURE ----------//
	mTextureContainer.SetProgram(mShader.Program());
	mTextureContainer.BindTexture(GL_TEXTURE0);
	mTextureContainer.SetTextureParameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
	mTextureContainer.SetTextureParameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
	mTextureContainer.SetTextureParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	mTextureContainer.SetTextureParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	mTextureContainer.LoadTexture("res\\container.jpg");
	mTextureContainer.GenerateTexture(GL_RGB, GL_RGB, GL_UNSIGNED_BYTE);
	mTextureContainer.GenerateMipmaps();
	mTextureContainer.FreeImageData();
	mTextureContainer.UnbindTexture();

	mTextureAwesomeFace.SetProgram(mShader.Program());
	mTextureAwesomeFace.BindTexture(GL_TEXTURE1);
	mTextureAwesomeFace.SetTextureParameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
	mTextureAwesomeFace.SetTextureParameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
	mTextureAwesomeFace.SetTextureParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	mTextureAwesomeFace.SetTextureParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	mTextureAwesomeFace.LoadTexture("res\\awesomeface.png");
	mTextureAwesomeFace.GenerateTexture(GL_RGB, GL_RGB, GL_UNSIGNED_BYTE);
	mTextureAwesomeFace.GenerateMipmaps();
	mTextureAwesomeFace.FreeImageData();
	mTextureAwesomeFace.UnbindTexture();
}

void CoordinateSystemsComponent::Draw(float DeltaSeconds)
{
		//Model matrix = modelToWorld; View matrix = worldToView; projection = Projection Matrix -> ortho/perspective
		glm::mat4 modelToWorld, worldToview, projection;
		modelToWorld = glm::rotate(modelToWorld, glm::radians((GLfloat)glfwGetTime() * 50.0f), glm::vec3(0.5f, 1.0f, 0.0f)); //Rotate -55 degress on the X axis

		//Since we want it to look like we're moving the camera backwards (positive Z axis), we instead move the entire scene foreward (negative Z axis)
		worldToview = glm::translate(worldToview, glm::vec3(0.0f, 0.0f, -3.0f));

		projection = glm::perspective(glm::radians(90.0f), (float)mApplication->GetWidth()/(float)mApplication->GetHeight(), 0.1f, 100.0f);
		glUseProgram(mShader.Program());

		mTextureContainer.BindTexture(GL_TEXTURE0);
		mTextureContainer.SetSampler2D("ourTexture");

		mTextureAwesomeFace.BindTexture(GL_TEXTURE1);
		mTextureAwesomeFace.SetSampler2D("ourTexture2");

		

		GLuint viewLocation = glGetUniformLocation(mShader.Program(), "view");
		glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(worldToview));
		GLuint projectionLocation = glGetUniformLocation(mShader.Program(), "projection");
		glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));

		glBindVertexArray(VAO);

		for (int i = 0; i < 10; ++i)
		{
			glm::mat4 cubesWorldSpace;
			cubesWorldSpace = glm::translate(cubesWorldSpace, mCubePositions[i]);
			cubesWorldSpace = glm::rotate(cubesWorldSpace, glm::radians((float)20 * (i + 1) * (float)glfwGetTime()), glm::vec3(1.0f, 0.3f, 0.5f));
			GLuint modelLocation = glGetUniformLocation(mShader.Program(), "model");
			glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(cubesWorldSpace));

			glDrawArrays(GL_TRIANGLES, 0, 36);

		}

		glBindVertexArray(0);
		glUseProgram(0);
	
}

