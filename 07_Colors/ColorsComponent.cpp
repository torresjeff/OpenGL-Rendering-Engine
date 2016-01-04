#include "ColorsComponent.h"

ColorsComponent::ColorsComponent(Application & application)
	: DrawableGameComponent(application)
{}

ColorsComponent::ColorsComponent(Application & application, Camera& camera)
	: DrawableGameComponent(application, camera)
{}

void ColorsComponent::Initialize()
{
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

	//---- CONTAINER ----//
	glGenVertexArrays(1, &cubeVao);
	glGenBuffers(1, &VBO);

	glBindVertexArray(cubeVao);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(GLfloat), &mVertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//---- LAMP ----//
	glGenVertexArrays(1, &lampVao);
	glBindVertexArray(lampVao);
	//We're going to use the same data for the lamp as the one that is already stored in the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	mContainerShader = Shader("shaders\\container.vert", "shaders\\container.frag");
	mLightShader = Shader("shaders\\light.vert", "shaders\\light.frag");

	mTextureContainer.SetProgram(mContainerShader.Program());
	mTextureContainer.BindTexture(GL_TEXTURE0);
	mTextureContainer.SetTextureParameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
	mTextureContainer.SetTextureParameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
	mTextureContainer.SetTextureParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	mTextureContainer.SetTextureParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	mTextureContainer.LoadTexture("res\\wall.jpg");
	mTextureContainer.GenerateTexture(GL_RGB, GL_RGB, GL_UNSIGNED_BYTE);
	mTextureContainer.GenerateMipmaps();
	mTextureContainer.FreeImageData();
	mTextureContainer.UnbindTexture();
}

void ColorsComponent::Draw(float DeltaSeconds)
{
	glm::mat4 model;
	//---- Container Shader ----//
	mContainerShader.UseProgram();
	glBindVertexArray(cubeVao);

	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -10.0f));
	model = glm::rotate(model, glm::radians(60.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
	
	GLint modelLocation = glGetUniformLocation(mContainerShader.Program(), "model");
	GLint viewLocation = glGetUniformLocation(mContainerShader.Program(), "view");
	GLint projectionLocation = glGetUniformLocation(mContainerShader.Program(), "projection");
	GLint objectColorLocation = glGetUniformLocation(mContainerShader.Program(), "objectColor");
	GLint lightColorLocation = glGetUniformLocation(mContainerShader.Program(), "lightColor");

	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetViewMatrix()));
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetProjectionMatrix()));

	glUniform3f(objectColorLocation, 1.0f, 0.5f, 0.31f);
	glUniform3f(lightColorLocation, 1.0f, 0.5f, 1.0f);

	mTextureContainer.BindTexture(GL_TEXTURE0);
	mTextureContainer.SetSampler2D("ourTexture");

	glDrawArrays(GL_TRIANGLES, 0, 36);

	glBindVertexArray(0);
	glUseProgram(0);

	//---- Lamp Shader ----//
	mLightShader.UseProgram();
	glBindVertexArray(lampVao);

	model = glm::mat4();
	model = glm::translate(model, glm::vec3(0.0f, 2.0f, -3.0f));

	modelLocation = glGetUniformLocation(mLightShader.Program(), "model");
	viewLocation = glGetUniformLocation(mLightShader.Program(), "view");
	projectionLocation = glGetUniformLocation(mLightShader.Program(), "projection");

	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetViewMatrix()));
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetProjectionMatrix()));

	glDrawArrays(GL_TRIANGLES, 0, 36);

	glBindVertexArray(0);
	glUseProgram(0);
}
