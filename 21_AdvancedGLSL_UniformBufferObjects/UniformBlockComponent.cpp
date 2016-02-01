#include "UniformBlockComponent.h"



UniformBlockComponent::UniformBlockComponent(Application& application, Camera& camera)
	: DrawableGameComponent(application, camera)
{}

void UniformBlockComponent::Initialize()
{
	// Vertices defined in counter-clockwise winding order.
	mContainerVertices =
	{
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,	0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,	1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,	1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,	1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,	0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,	0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,	0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,		1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,		1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,		1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,	0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,	0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,	0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,	1.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,	1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,	1.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,	0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,	0.0f, 0.0f,

		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,	0.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,	1.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,	1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,	1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,	0.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,	0.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,	0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,	1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,	1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,	1.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,	0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,	0.0f, 0.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,	0.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,	1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,	1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,	1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,	0.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,	0.0f, 0.0f
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

	mPointLightPositions =
	{
		glm::vec3(0.7f, 0.2f, 2.0f),
		glm::vec3(2.3f, -3.3f, -4.0f),
		glm::vec3(-4.0f, 2.0f, -12.0f),
		glm::vec3(0.0f, 0.0f, -3.0f)
	};

	mTextureNames = 
	{
		"res/right.jpg", // GL_TEXTURE_CUBE_MAP_POSITIVE_X
		"res/left.jpg", // GL_TEXTURE_CUBE_MAP_NEGATIVE_X
		"res/top.jpg", // GL_TEXTURE_CUBE_MAP_POSITIVE_Y
		"res/bottom.jpg", // GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
		"res/back.jpg", // GL_TEXTURE_CUBE_MAP_POSITIVE_Z
		"res/front.jpg" // GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	};

	mSkyboxVertices =
	{
		// Positions          
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		-1.0f,  1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f,  1.0f
	};

	int texWidth, texHeight;

	//CUBEMAP
	glGenVertexArrays(1, &mCubemapVAO);
	glGenBuffers(1, &mCubemapVBO);
	glBindVertexArray(mCubemapVAO);
	glBindBuffer(GL_ARRAY_BUFFER, mCubemapVBO);
	glBufferData(GL_ARRAY_BUFFER, mSkyboxVertices.size() * sizeof(GLfloat), &mSkyboxVertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &mCubemap);
	glBindTexture(GL_TEXTURE_CUBE_MAP, mCubemap);
	unsigned char* image;
	for (int i = 0; i < mTextureNames.size(); ++i)
	{
		//Load each image in the order stored in the mTextureNames vector
		//diffuseMap = SOIL_load_image(mTextureNames[i], &texWidth, &texHeight, nullptr, SOIL_LOAD_RGB);
		////Generate an OpenGL texture for each face of the cube, starting with the right face (POSITIVE_X). The order is as specifiec in the mTextureNames vector.
		//glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, diffuseMap);
		//SOIL_free_image_data(diffuseMap);
		image = SOIL_load_image(mTextureNames[i], &texWidth, &texHeight, 0, SOIL_LOAD_RGB);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	//Generate VBOs and VAO.
	glGenVertexArrays(1, &mContainerVAO);
	glGenBuffers(1, &mContainerVBO);

	//Bind VAO and buffers, and fill in buffer data
	glBindVertexArray(mContainerVAO);
	glBindBuffer(GL_ARRAY_BUFFER, mContainerVBO);
	glBufferData(GL_ARRAY_BUFFER, mContainerVertices.size() * sizeof(GLfloat), &mContainerVertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	
	
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &mTextureDiffuse);
	glBindTexture(GL_TEXTURE_2D, mTextureDiffuse);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* diffuseMap = SOIL_load_image("res/diffuseMap.bmp", &texWidth, &texHeight, nullptr, SOIL_LOAD_AUTO);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, diffuseMap);
	glGenerateMipmap(GL_TEXTURE_2D);

	SOIL_free_image_data(diffuseMap);
	glBindTexture(GL_TEXTURE_2D, 0);

	glActiveTexture(GL_TEXTURE1);
	glGenTextures(1, &mTextureSpecular);
	glBindTexture(GL_TEXTURE_2D, mTextureSpecular);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* specularMap = SOIL_load_image("res/specularMap.bmp", &texWidth, &texHeight, nullptr, SOIL_LOAD_AUTO);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, specularMap);
	glGenerateMipmap(GL_TEXTURE_2D);

	SOIL_free_image_data(specularMap);
	glBindTexture(GL_TEXTURE_2D, 0);

	

	//---------- UNIFORM BUFFER OBJECT ----------//
	glGenBuffers(1, &mUniformBufferObject);
	glBindBuffer(GL_UNIFORM_BUFFER, mUniformBufferObject);
	glBufferData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4), NULL, GL_STATIC_DRAW); //allocate enough memory to hold to 4x4 matrices (view and projection)
	glBindBuffer(GL_UNIFORM_BUFFER, 0);



	//Unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	mShaderContainer = Shader("shaders/container.vert", "shaders/container.frag");
	mShaderCubemap = Shader("shaders/cubemap.vert", "shaders/cubemap.frag");


	//Bind the uniform buffer we just created to binding point 2 (so it corresponds with our shaders).
	glBindBufferRange(GL_UNIFORM_BUFFER, 2, mUniformBufferObject, 0, 2 * sizeof(glm::mat4));
	//Fill the first half of the buffer with the projection matrix
	glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(mCamera->GetProjectionMatrix()));
	glBindBuffer(GL_UNIFORM_BUFFER, 0);

	//We use this when we don't specify the "binding" layout (eg. layout(binding = 2)) in our shaders. This binding layout is only available in OpenGL 4.2+
	/*GLint containerMatricesLocation = glGetUniformLocation(mShaderContainer.Program(), "Matrices");
	GLint cubemapMatricesLocation = glGetUniformLocation(mShaderCubemap.Program(), "Matrices");

	glUniformBlockBinding(mShaderContainer.Program(), containerMatricesLocation, 2);
	glUniformBlockBinding(mShaderCubemap.Program(), cubemapMatricesLocation, 2);
	*/
}

void UniformBlockComponent::Draw(float DeltaSeconds)
{
	//GLint viewLocation;
	//GLint projectionLocation;
	GLint skyboxLocation;

	glBindBuffer(GL_UNIFORM_BUFFER, mUniformBufferObject);
	glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(mCamera->GetViewMatrix()));

	glDepthMask(GL_TRUE);
	mShaderContainer.UseProgram();
	glBindVertexArray(mContainerVAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mTextureDiffuse);

	//Set up uniforms
	// MODEL, VIEW, PROJECTION
	GLint modelLocation = glGetUniformLocation(mShaderContainer.Program(), "model");
	if (modelLocation == -1)
	{
		cout << "Model location = -1" << endl;
		return;
	}

	/*viewLocation = glGetUniformLocation(mShaderContainer.Program(), "view");
	if (viewLocation == -1)
	{
		cout << "View location = -1" << endl;
		return;
	}

	projectionLocation = glGetUniformLocation(mShaderContainer.Program(), "projection");
	if (projectionLocation == -1)
	{
		cout << "Projection location = -1" << endl;
		return;
	}*/


	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_CUBE_MAP, mCubemap);
	skyboxLocation = glGetUniformLocation(mShaderCubemap.Program(), "skybox");
	if (skyboxLocation == -1)
	{
		cout << "skyboxLocation = -1";
	}
	glUniform1i(skyboxLocation, 2);

	/*glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetViewMatrix()));
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetProjectionMatrix()));*/
	
	
	GLint matDiffuseLocation = glGetUniformLocation(mShaderContainer.Program(), "material.diffuse");
	glUniform1i(matDiffuseLocation, 0);


	for (size_t i = 0; i < mCubePositions.size(); ++i)
	{
		glm::mat4 model;
		model = glm::translate(glm::mat4(), mCubePositions[i]);
		float angle = 20.0f * i;
		model = glm::rotate(model, glm::radians(angle), glm::vec3(0.2f, 0.5f, 0.5f));

		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	/*DRAW THE SKYBOX LAST (OPTIMIZATION PURPOSES), WITHOUT DEPTH TESTING*/
	//glDepthMask(GL_FALSE); //Disable depth testing because we want the skybox to always be in the background, without affecting the depth buffer. Any object can be rendered on top of the skybox.
	mShaderCubemap.UseProgram();
	glBindVertexArray(mCubemapVAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, mCubemap);
	/*viewLocation = glGetUniformLocation(mShaderCubemap.Program(), "view");
	if (viewLocation == -1)
	{
		cout << "view = -1";
	}
	projectionLocation = glGetUniformLocation(mShaderCubemap.Program(), "projection");
	if (projectionLocation == -1)
	{
		cout << "projection = -1";
	}*/
	skyboxLocation = glGetUniformLocation(mShaderCubemap.Program(), "skybox");
	if (skyboxLocation == -1)
	{
		cout << "skyboxLocation = -1";
	}

	
	//We remove the translation part of the view matrix, so it doesn't move the skybox, preventing the player from getting outside of it.
	//This gives the impression that the world is extremely large.
	glm::mat4 view = glm::mat4(glm::mat3(mCamera->GetViewMatrix())); 
																	
	/*glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetProjectionMatrix()));*/

	glDrawArrays(GL_TRIANGLES, 0, 36);
	

	

	glUseProgram(0);
	glBindVertexArray(0);
}
