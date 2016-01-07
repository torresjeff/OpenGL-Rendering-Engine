#include "StencilTestingComponent.h"

StencilTestingComponent::StencilTestingComponent(Application& application, Camera& camera)
	: DrawableGameComponent(application, camera)
{}

void StencilTestingComponent::Initialize()
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
	mShaderBorder = Shader("shaders/container.vert", "shaders/border.frag");
}

void StencilTestingComponent::Draw(float DeltaSeconds)
{
	mShaderContainer.UseProgram();
	glBindVertexArray(mVAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mTextureDiffuse);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, mTextureSpecular);

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

	glm::mat4 viewMatrix = mCamera->GetViewMatrix();
	glm::mat4 projectionMatrix = mCamera->GetProjectionMatrix();
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	//TODO: look for steel propoerties for the steel borders (shininess)
	// MATERIAL PROPERTIES
	GLint matDiffuseLocation = glGetUniformLocation(mShaderContainer.Program(), "material.diffuse");
	GLint matSpecularLocation = glGetUniformLocation(mShaderContainer.Program(), "material.specular");
	GLint matShineLocation = glGetUniformLocation(mShaderContainer.Program(), "material.shininess");
	glUniform1i(matDiffuseLocation, 0);
	glUniform1i(matSpecularLocation, 1);
	glUniform1f(matShineLocation, 8.0f);

	//DIRECTIONAL LIGHT
	GLint lightDirectionLocation;
	GLint lightAmbientLocation;
	GLint lightDiffuseLocation;
	GLint lightSpecularLocation;
	lightDirectionLocation = glGetUniformLocation(mShaderContainer.Program(), "directionalLight.direction");
	lightAmbientLocation = glGetUniformLocation(mShaderContainer.Program(), "directionalLight.ambient");
	lightDiffuseLocation = glGetUniformLocation(mShaderContainer.Program(), "directionalLight.diffuse");
	lightSpecularLocation = glGetUniformLocation(mShaderContainer.Program(), "directionalLight.specular");
	glUniform3f(lightDirectionLocation, -0.2f, -1.0f, -0.3f);
	glUniform3f(lightAmbientLocation, 0.2f, 0.2f, 0.2f);
	glUniform3f(lightDiffuseLocation, 1.0f, 1.0f, 1.0f); // Let’s darken the light a bit to fit the scene
	glUniform3f(lightSpecularLocation, 1.0f, 1.0f, 1.0f);

	// POINT LIGHT
	GLint lightPositionLocation;
	for (int i = 0; i < mPointLightPositions.size(); ++i)
	{
		lightPositionLocation = glGetUniformLocation(mShaderContainer.Program(), ("pointLights[" + std::to_string(i) + "].position").c_str());
		lightAmbientLocation = glGetUniformLocation(mShaderContainer.Program(), ("pointLights[" + std::to_string(i) + "].ambient").c_str());
		lightDiffuseLocation = glGetUniformLocation(mShaderContainer.Program(), ("pointLights[" + std::to_string(i) + "].diffuse").c_str());
		lightSpecularLocation = glGetUniformLocation(mShaderContainer.Program(), ("pointLights[" + std::to_string(i) + "].specular").c_str());
		GLint lightIntensityLocation = glGetUniformLocation(mShaderContainer.Program(), ("pointLights[" + std::to_string(i) + "].intensity").c_str());
		GLint lightKcLocation = glGetUniformLocation(mShaderContainer.Program(), ("pointLights[" + std::to_string(i) + "].Kc").c_str());
		GLint lightKlLocation = glGetUniformLocation(mShaderContainer.Program(), ("pointLights[" + std::to_string(i) + "].Kl").c_str());
		GLint lightKqLocation = glGetUniformLocation(mShaderContainer.Program(), ("pointLights[" + std::to_string(i) + "].Kq").c_str());
		glUniform3f(lightPositionLocation, mPointLightPositions[i].x, mPointLightPositions[i].y, mPointLightPositions[i].z);
		glUniform3f(lightAmbientLocation, 0.2f, 0.2f, 0.2f);
		glUniform3f(lightDiffuseLocation, 1.0f, 1.0f, 1.0f);
		glUniform3f(lightSpecularLocation, 1.0f, 1.0f, 1.0f);
		glUniform1f(lightIntensityLocation, 0.5f);
		glUniform1f(lightKcLocation, 1.0f);
		glUniform1f(lightKlLocation, 0.09f);
		glUniform1f(lightKqLocation, 0.032f);
	}

	
	//Camera position and direction
	GLint cameraPositionLocation = glGetUniformLocation(mShaderContainer.Program(), "cameraPosition");
	glm::vec3 camPos = mCamera->GetPosition();
	glm::vec3 camDirection = mCamera->GetDirection();
	glUniform3f(cameraPositionLocation, camPos.x, camPos.y, camPos.z);

	// SPOT LIGHT
	lightPositionLocation = glGetUniformLocation(mShaderContainer.Program(), "spotLight.position");
	lightDirectionLocation = glGetUniformLocation(mShaderContainer.Program(), "spotLight.direction");
	GLint lightInnerAngleLocation = glGetUniformLocation(mShaderContainer.Program(), "spotLight.innerAngle");
	GLint lightOuterAngleLocation = glGetUniformLocation(mShaderContainer.Program(), "spotLight.outerAngle");
	lightAmbientLocation = glGetUniformLocation(mShaderContainer.Program(), "spotLight.ambient");
	lightDiffuseLocation = glGetUniformLocation(mShaderContainer.Program(), "spotLight.diffuse");
	lightSpecularLocation = glGetUniformLocation(mShaderContainer.Program(), "spotLight.specular");
	glUniform3f(lightPositionLocation, camPos.x, camPos.y, camPos.z); //We use the camera's position, simulating a flashlight (follows the player)
	glUniform3f(lightDirectionLocation, camDirection.x, camDirection.y, camDirection.z);
	glUniform1f(lightInnerAngleLocation, glm::radians(5.0f));
	glUniform1f(lightOuterAngleLocation, glm::radians(20.0f)); //TODO: implement attenuation, the spot light shines infinitely.
	glUniform3f(lightAmbientLocation, 0.2f, 0.2f, 0.2f);
	glUniform3f(lightDiffuseLocation, 1.0f, 1.0f, 1.0f);
	glUniform3f(lightSpecularLocation, 1.0f, 1.0f, 1.0f);


	glStencilFunc(GL_ALWAYS, 1, 0xFF);
	glStencilMask(0xFF);

	for (size_t i = 0; i < mCubePositions.size(); ++i)
	{
		glm::mat4 model;
		float angle = 20.0f * i;
		model = glm::translate(glm::mat4(), mCubePositions[i]);
		//model = glm::rotate(model, glm::radians(angle), glm::vec3(0.2f, 0.5f, 0.5f));

		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
	glStencilMask(0x00);
	//glDisable(GL_DEPTH_TEST);

	mShaderBorder.UseProgram();
	modelLocation = glGetUniformLocation(mShaderBorder.Program(), "model");
	viewLocation = glGetUniformLocation(mShaderBorder.Program(), "view");
	projectionLocation = glGetUniformLocation(mShaderBorder.Program(), "projection");
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	for (size_t i = 0; i < mCubePositions.size(); ++i)
	{
		glm::mat4 model;
		float angle = 20.0f * i;
		model = glm::translate(glm::mat4(), mCubePositions[i]);
		//model = glm::rotate(model, glm::radians(angle), glm::vec3(0.2f, 0.5f, 0.5f));
		model = glm::scale(model, glm::vec3(1.1f, 1.1f, 1.1f));
		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
	glStencilMask(0xFF);
	//glEnable(GL_DEPTH_TEST);

	//glStencilMask(0x00);
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

	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	/*for (int i = 0; i < mPointLightPositions.size(); ++i)
	{
		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(glm::translate(glm::mat4(), mPointLightPositions[i])));
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}*/

	glUseProgram(0);
	glBindVertexArray(0);
}
