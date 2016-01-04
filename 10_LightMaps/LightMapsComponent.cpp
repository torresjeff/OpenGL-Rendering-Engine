#include "LightMapsComponent.h"

LightMapsComponent::LightMapsComponent(Application& application, Camera& camera)
	: DrawableGameComponent(application, camera)
{}

void LightMapsComponent::Initialize()
{
	mVertices =
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

	//Generate VBOs and VAO.
	glGenVertexArrays(1, &mVAO);
	glGenBuffers(1, &mVBO);

	//Bind VAO and buffers, and fill in buffer data
	glBindVertexArray(mVAO);
	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(GLfloat), &mVertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));

	
	int texWidth, texHeight;
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

	//Unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	mShaderContainer = Shader("shaders/container.vert", "shaders/container.frag");
	mShaderLight = Shader("shaders/light.vert", "shaders/light.frag");

	mContainerTransform = glm::rotate(mContainerTransform, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	mLightTransform = glm::translate(glm::mat4(), lightPosition);
}

void LightMapsComponent::Draw(float DeltaSeconds)
{
	mShaderContainer.UseProgram();
	glBindVertexArray(mVAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mTextureDiffuse);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, mTextureSpecular);

	//Set up uniforms
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


	GLint lightPositionLocation = glGetUniformLocation(mShaderContainer.Program(), "light.position");
	GLint cameraPositionLocation = glGetUniformLocation(mShaderContainer.Program(), "cameraPosition");

	//TODO: look for steel propoerties for the steel borders (shininess)
	GLint matDiffuseLocation = glGetUniformLocation(mShaderContainer.Program(), "material.diffuse");
	GLint matSpecularLocation = glGetUniformLocation(mShaderContainer.Program(), "material.specular");
	GLint matShineLocation = glGetUniformLocation(mShaderContainer.Program(), "material.shininess");
	glUniform1i(matDiffuseLocation, 0);
	glUniform1i(matSpecularLocation, 1);
	glUniform1f(matShineLocation, 8.0f);

	GLint lightAmbientLocation = glGetUniformLocation(mShaderContainer.Program(), "light.ambient");
	GLint lightDiffuseLocation = glGetUniformLocation(mShaderContainer.Program(), "light.diffuse");
	GLint lightSpecularLocation = glGetUniformLocation(mShaderContainer.Program(), "light.specular");
	glUniform3f(lightAmbientLocation, 0.2f, 0.2f, 0.2f);
	glUniform3f(lightDiffuseLocation, 1.0f, 1.0f, 1.0f); // Let’s darken the light a bit to fit the scene
	glUniform3f(lightSpecularLocation, 1.0f, 1.0f, 1.0f);


	//----- Uncomment this to make the light move in a circle.
	/*float time = glfwGetTime();
	float movementX = 8 * cos(time);
	float movementY = 8 * sin(time);

	mLightTransform = glm::translate(glm::mat4(), glm::vec3(movementX, 3.0f, movementY));
	lightPosition = glm::vec3(movementX, 4.0f, movementY);*/

	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(mContainerTransform));
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetViewMatrix()));
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetProjectionMatrix()));
	
	glUniform3f(lightPositionLocation, lightPosition.x, lightPosition.y, lightPosition.z);
	glm::vec3 camPos = mCamera->GetPosition();
	glUniform3f(cameraPositionLocation, camPos.x, camPos.y, camPos.z);
	glDrawArrays(GL_TRIANGLES, 0, 36);

	mShaderLight.UseProgram();
	//Set up uniforms
	modelLocation = glGetUniformLocation(mShaderLight.Program(), "model");
	if (modelLocation == -1)
	{
		cout << "Model location = -1" << endl;
		return;
	}

	viewLocation = glGetUniformLocation(mShaderLight.Program(), "view");
	if (viewLocation == -1)
	{
		cout << "View location = -1" << endl;
		return;
	}

	projectionLocation = glGetUniformLocation(mShaderLight.Program(), "projection");
	if (projectionLocation == -1)
	{
		cout << "Projection location = -1" << endl;
		return;
	}

	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(mLightTransform));
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetViewMatrix()));
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetProjectionMatrix()));

	glDrawArrays(GL_TRIANGLES, 0, 36);

	glUseProgram(0);
	glBindVertexArray(0);
}
