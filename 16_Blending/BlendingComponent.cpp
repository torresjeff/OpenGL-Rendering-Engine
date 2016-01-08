#include "BlendingComponent.h"

BlendingComponent::BlendingComponent(Application& application, Camera& camera)
	: DrawableGameComponent(application, camera)
{}

void BlendingComponent::Initialize()
{
	mCubeVertices =
	{
		//FRONT FACE
		//Positions				//Normals			//Texture Coordinates
		0.5f,  0.5f, 0.5f,		0.0f, 0.0f, 1.0f,	 1.0f, 1.0f,
		0.5f, -0.5f, 0.5f,		0.0f, 0.0f, 1.0f,	 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f,		0.0f, 0.0f, 1.0f,	 0.0f, 0.0f,
		0.5f,  0.5f, 0.5f,		0.0f, 0.0f, 1.0f,	 1.0f, 1.0f,
		-0.5f, -0.5f, 0.5f,		0.0f, 0.0f, 1.0f,	 0.0f, 0.0f,
		-0.5f,  0.5f, 0.5f,		0.0f, 0.0f, 1.0f,	 0.0f, 1.0f,

		//BACK FACE												
		0.5f,  0.5f, -0.5f,		0.0f, 0.0f, -1.0f,	 1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,		0.0f, 0.0f, -1.0f,	 1.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, -1.0f,	 0.0f, 0.0f,
		0.5f,  0.5f, -0.5f,		0.0f, 0.0f, -1.0f,	 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, -1.0f,	 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 0.0f, -1.0f,	 0.0f, 1.0f,

		//RIGHT FACE											
		0.5f,  0.5f, -0.5f,		1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,		1.0f, 0.0f, 0.0f,	 1.0f, 0.0f,
		0.5f, -0.5f, 0.5f,		1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,
		0.5f,  0.5f, -0.5f,		1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,
		0.5f, -0.5f, 0.5f,		1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,
		0.5f,  0.5f, 0.5f,		1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		//LEFT FACE
		-0.5f,  0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,
		-0.5f, -0.5f, 0.5f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,
		-0.5f,  0.5f, 0.5f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		//TOP FACE
		0.5f,  0.5f, -0.5f,		 0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,
		0.5f,  0.5f, 0.5f,		 0.0f, 1.0f, 0.0f,	 1.0f, 0.0f,
		-0.5f,  0.5f, 0.5f,		 0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,
		0.5f,  0.5f, -0.5f,		 0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,
		-0.5f,  0.5f, 0.5f,		 0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	 0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		//BOTTOM FACE
		0.5f,  -0.5f, -0.5f,	0.0f, -1.0f, 0.0f,	 1.0f, 1.0f,
		0.5f,  -0.5f, 0.5f,		0.0f, -1.0f, 0.0f,	 1.0f, 0.0f,
		-0.5f,  -0.5f, 0.5f,	0.0f, -1.0f, 0.0f,	 0.0f, 0.0f,
		0.5f,  -0.5f, -0.5f,	0.0f, -1.0f, 0.0f,	 1.0f, 1.0f,
		-0.5f, -0.5f, 0.5f,		0.0f, -1.0f, 0.0f,	 0.0f, 0.0f,
		-0.5f,  -0.5f, -0.5f,	0.0f, -1.0f, 0.0f, 	 0.0f, 1.0f
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

	mQuadVertices = 
	{
		//Positions				//UVs
		-0.5f, 0.5f, 0.0f,		0.0f, 1.0f,
		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f,
		0.5f, 0.5f, 0.0f,		1.0f, 1.0f,

		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f,
		0.5f, 0.5f, 0.0f,		1.0f, 1.0f,
		0.5f, -0.5f, 0.0f,		1.0f, 0.0f,
	};

	mGrassPositions = 
	{
		glm::vec3(0.0f, 0.0f, 2.0f),
		glm::vec3(3.0f, 5.0f, -15.0f),
		glm::vec3(-0.25f, 0.0f, 2.5f)
	};

	mWindowPositions = 
	{
		glm::vec3(0.0f, 3.0f, 1.0f),
		glm::vec3(3.0f, 5.0f, -15.0f),
		glm::vec3(-0.25f, 3.0f, 2.5f)
	};

	mPointLightPositions =
	{
		glm::vec3(0.7f, 0.2f, 2.0f),
		glm::vec3(2.3f, -3.3f, -4.0f),
		glm::vec3(-4.0f, 2.0f, -12.0f),
		glm::vec3(0.0f, 0.0f, -3.0f)
	};

	//Generate VBOs and VAO.
	glGenVertexArrays(1, &mContainerVAO);
	glGenBuffers(1, &mContainerVBO);

	//Bind VAO and buffers, and fill in buffer data
	glBindVertexArray(mContainerVAO);
	glBindBuffer(GL_ARRAY_BUFFER, mContainerVBO);
	glBufferData(GL_ARRAY_BUFFER, mCubeVertices.size() * sizeof(GLfloat), &mCubeVertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));

	
	int texWidth, texHeight;
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &mTextureContainerDiffuse);
	glBindTexture(GL_TEXTURE_2D, mTextureContainerDiffuse);
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
	glGenTextures(1, &mTextureContainerSpecular);
	glBindTexture(GL_TEXTURE_2D, mTextureContainerSpecular);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* specularMap = SOIL_load_image("res/specularMap.bmp", &texWidth, &texHeight, nullptr, SOIL_LOAD_AUTO);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, specularMap);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(specularMap);
	glBindTexture(GL_TEXTURE_2D, 0);

	//Unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);

	glGenVertexArrays(1, &mQuadVAO);
	glBindVertexArray(mQuadVAO);
	glGenBuffers(1, &mQuadVBO);
	glBindBuffer(GL_ARRAY_BUFFER, mQuadVBO);
	glBufferData(GL_ARRAY_BUFFER, mQuadVertices.size() * sizeof(GLfloat), &mQuadVertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));

	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &mTextureGrass);
	glBindTexture(GL_TEXTURE_2D, mTextureGrass);

	diffuseMap = SOIL_load_image("res/grass.png", &texWidth, &texHeight, NULL, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, diffuseMap);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); //TODO: chanmge to clamp to edge
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	SOIL_free_image_data(diffuseMap);

	glActiveTexture(GL_TEXTURE1);
	glGenTextures(1, &mTextureWindow);
	glBindTexture(GL_TEXTURE_2D, mTextureWindow);

	diffuseMap = SOIL_load_image("res/blending_transparent_window.png", &texWidth, &texHeight, NULL, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, diffuseMap);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	SOIL_free_image_data(diffuseMap);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	mShaderContainer = Shader("shaders/container.vert", "shaders/container.frag");
	mShaderLight = Shader("shaders/light.vert", "shaders/light.frag");
	mShaderQuad = Shader("shaders/quad.vert", "shaders/quad.frag");
}

void BlendingComponent::Draw(float DeltaSeconds)
{
	mShaderContainer.UseProgram();
	glBindVertexArray(mContainerVAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mTextureContainerDiffuse);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, mTextureContainerSpecular);

	//Set up uniforms
	// MODEL, VIEW, PROJECTION
	GLint modelLocation = glGetUniformLocation(mShaderContainer.Program(), "model");
	if (modelLocation == -1)
	{
		cout << "Model location = -1" << endl;
		return;
	}

	GLint viewLocation = glGetUniformLocation(mShaderContainer.Program(), "view");
	if (viewLocation == -1)
	{
		cout << "View location = -1" << endl;
		return;
	}

	GLint projectionLocation = glGetUniformLocation(mShaderContainer.Program(), "projection");
	if (projectionLocation == -1)
	{
		cout << "Projection location = -1" << endl;
		return;
	}

	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetViewMatrix()));
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetProjectionMatrix()));

	//TODO: look for steel propoerties for the steel borders (shininess)
	// MATERIAL PROPERTIES
	GLint matDiffuseLocation = glGetUniformLocation(mShaderContainer.Program(), "material.diffuse");
	GLint matSpecularLocation = glGetUniformLocation(mShaderContainer.Program(), "material.specular");
	GLint matShineLocation = glGetUniformLocation(mShaderContainer.Program(), "material.shininess");
	glUniform1i(matDiffuseLocation, 0);
	glUniform1i(matSpecularLocation, 1);
	glUniform1f(matShineLocation, 8.0f);


	
	//Camera position and direction
	GLint cameraPositionLocation = glGetUniformLocation(mShaderContainer.Program(), "cameraPosition");
	glm::vec3 camPos = mCamera->GetPosition();
	glm::vec3 camDirection = mCamera->GetDirection();
	glUniform3f(cameraPositionLocation, camPos.x, camPos.y, camPos.z);


	for (size_t i = 0; i < mCubePositions.size(); ++i)
	{
		glm::mat4 model;
		model = glm::translate(glm::mat4(), mCubePositions[i]);
		float angle = 20.0f * i;
		model = glm::rotate(model, glm::radians(angle), glm::vec3(0.2f, 0.5f, 0.5f));

		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	mShaderQuad.UseProgram();
	glBindVertexArray(mQuadVAO);
	
	std::map<float, TextureInfo> sortedTextures; //We use a map because it automatically sorts the elements. Our key is the distance from the camera to the object. Then we draw in reversed order.
	//Grass positions
	for (unsigned int i = 0; i < mGrassPositions.size(); ++i)
	{
		TextureInfo info;
		info.index = i;
		info.t = GRASS;
		float distance = glm::length(camPos - mGrassPositions[i]);
		sortedTextures[distance] = info;
	}

	//Window positions
	for (unsigned int i = 0; i < mWindowPositions.size(); ++i)
	{
		TextureInfo info;
		info.index = i;
		info.t = WINDOW;
		float distance = glm::length(camPos - mWindowPositions[i]);
		sortedTextures[distance] = info;
	}

	glActiveTexture(GL_TEXTURE0);
	modelLocation = glGetUniformLocation(mShaderQuad.Program(), "model");
	viewLocation = glGetUniformLocation(mShaderQuad.Program(), "view");
	projectionLocation = glGetUniformLocation(mShaderQuad.Program(), "projection");
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetViewMatrix()));
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetProjectionMatrix()));

	for (auto it = sortedTextures.rbegin(); it != sortedTextures.rend(); ++it)
	{
		GLint textureLocation = glGetUniformLocation(mShaderQuad.Program(), "tex");
		if (textureLocation == -1)
		{
			std::cout << "texture not found\n";
		}


		switch (it->second.t)
		{
		case GRASS:
			glBindTexture(GL_TEXTURE_2D, mTextureGrass);
			glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(glm::translate(glm::mat4(), mGrassPositions[it->second.index])));
			glUniform1i(textureLocation, 0);
			break;
		case WINDOW:
			glBindTexture(GL_TEXTURE_2D, mTextureWindow);
			glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(glm::translate(glm::mat4(), mWindowPositions[it->second.index])));
			glUniform1i(textureLocation, 0);
			break;
			}

		glDrawArrays(GL_TRIANGLES, 0, 6);
	}

	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);
	glBindVertexArray(0);
}
