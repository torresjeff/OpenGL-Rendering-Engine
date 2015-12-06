#include "CameraComponent.h"


CameraComponent::CameraComponent(Application & application)
	: DrawableGameComponent(application)
{}

CameraComponent::CameraComponent(Application & application, Camera& camera)
	: DrawableGameComponent(application, camera)
{}

void CameraComponent::Initialize()
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

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(GLfloat), &mVertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	mShader = Shader("shaders/vertexshader.vert", "shaders/fragmentshader.frag");

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
	
	//---------- TEXTURES ----------//
	mTextureContainer.SetProgram(mShader.Program());
	mTextureContainer.BindTexture(GL_TEXTURE0);
	mTextureContainer.SetTextureParameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
	mTextureContainer.SetTextureParameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
	mTextureContainer.SetTextureParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	mTextureContainer.SetTextureParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	mTextureContainer.LoadTexture("res\\wall.jpg");
	mTextureContainer.GenerateTexture(GL_RGB, GL_RGB, GL_UNSIGNED_BYTE);
	mTextureContainer.GenerateMipmaps();
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
	mTextureAwesomeFace.UnbindTexture();
}


void CameraComponent::Draw(float DeltaSeconds)
{
	//---- Note: all this is easily achieved using the glm::lookAt function, which does all the cross products for us and returns the final lookAt matrix. ----//
	//glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f); // in world space
	//glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f); // in world space
	//glm::vec3 cameraDirection = glm::normalize(cameraPosition - cameraTarget); //The direction actually points to the reverse direction of what it is targeting
	//glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f); //We use this up vector (world space) to calculate the right vector of the camera using the cross product.
	//glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
	//glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);
	
	
	//1st parameter = camera position (in world space), 2nd parameter = camera's target (in world space), 3rd parameter = up vector (in world space, usually <0.0f, 1.0f, 0.0f>), can also be local up of the camera
	// Making the target = cameraPos + cameraFront, ensures that the camera is always looking at the target direction/front and not a single fixed point.
	cameraPos.y = 0.0f;
	/*glm::mat4 viewMatrix = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);*/
	
	//We calculate it every frame because of the zoom in functionality, which can change the fov value.
	//glm::mat4 projectionMatrix = glm::perspective(glm::radians(fov), (float)mApplication->GetWidth()/(float)mApplication->GetHeight(), 0.01f, 100.0f);
	
	mShader.UseProgram();

	mTextureContainer.BindTexture(GL_TEXTURE0);
	mTextureContainer.SetSampler2D("ourTexture");
	
	mTextureAwesomeFace.BindTexture(GL_TEXTURE1);
	mTextureAwesomeFace.SetSampler2D("ourTexture2");
	
	GLuint viewLocation = glGetUniformLocation(mShader.Program(), "view");
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetViewMatrix()));
	GLuint projectionLocation = glGetUniformLocation(mShader.Program(), "projection");
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetProjectionMatrix()));
	
	glBindVertexArray(VAO);
	
	for (int i = 0; i < 10; ++i)
	{
		glm::mat4 cubesWorldSpace;
		cubesWorldSpace = glm::translate(cubesWorldSpace, mCubePositions[i]);
		cubesWorldSpace = glm::rotate(cubesWorldSpace, glm::radians((float)20 * (i+1) * (float)glfwGetTime()), glm::vec3(1.0f, 0.3f, 0.5f));
		GLuint modelLocation = glGetUniformLocation(mShader.Program(), "model");
		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(cubesWorldSpace));
	
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
	
	glBindVertexArray(0);
}