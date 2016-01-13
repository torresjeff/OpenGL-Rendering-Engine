#include "FrambuffersComponent.h"

FrambuffersComponent::FrambuffersComponent(Application& application, Camera& camera)
	: DrawableGameComponent(application, camera)
{}

void FrambuffersComponent::Initialize()
{
	mVerticesContainer =
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

	mVerticesQuad =
	{
		// Positions   // TexCoords
		-1.0f,  1.0f,  0.0f, 1.0f,
		-1.0f, -1.0f,  0.0f, 0.0f,
		1.0f, -1.0f,  1.0f, 0.0f,

		-1.0f,  1.0f,  0.0f, 1.0f,
		1.0f, -1.0f,  1.0f, 0.0f,
		1.0f,  1.0f,  1.0f, 1.0f
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

	//---------------- FRAMEBUFFER -------------//
	glGenFramebuffers(1, &mFBO);
	//Bind it as the active framebuffer
	glBindFramebuffer(GL_FRAMEBUFFER, mFBO); // By binding to GL_FRAMEBUFFER all READ AND WRITE framebuffer operations will affect the currently bound framebuffer.
											// To bind a framebuffer to a read target specifically use GL_READ_FRAMEBUFFER, or to write only to GL_DRAW_FRAMEBUFFER.
											// The framebuffer bound to GL_READ_FRAMEBUFFER is then used for all read operations like glReadPixels and the framebuffer bound to GL_DRAW_FRAMEBUFFER is used as the destination for rendering, clearing and other write operations.

	// For a framebuffer to be complete, the following requirements must be met:
	// - We have to attach at least one buffer(color, depth or stencil buffer).
	// - There should be at least one color attachment.
	// - All attachments should be complete as well (reserved memory).
	// - Each buffer should have the same number of samples.
	
	// Use a texture as our color buffer. We can later access this texture from our shaders for post-processing effects.
	// The texture will be drawn unto a quad that covers the whole screen.
	// Right now we're only allocating memory for the texture. The texture will be filled when we issue the rendering commands.
	glGenTextures(1, &mFramebufferColorTexture);
	glBindTexture(GL_TEXTURE_2D, mFramebufferColorTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mApplication->GetWidth(), mApplication->GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	//Attach the texture to the framebuffer to be used as the color buffer:
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mFramebufferColorTexture, 0); // 0 = mipmap level

	// NOTE: we can also use textures as our depth/stencil buffers.
	// To use as our depth buffer: specify the attachment as GL_DEPTH_ATTACHMENT instead of GL_COLOR_ATTACHMENT0. Specify the texture's format and internal format as GL_DEPTH_COMPONENT instead of GL_RGB.
	// To use as our stencil buffer: specify the attachment as GL_STENCIL_ATTACHMENT. Specify the texture's format and internal format as GL_STENCIL_INDEX.
	// To use one texture for both our depth/stencil buffer: set the texture's formats to GL_DEPTH24_STENCIL8, and set the attachment type to GL_DEPTH_STENCIL_ATTACHMENT.
	
	// RENDERBUFFER OBJECTS: usually used as write-only buffers. The general rule is to use Renderbuffer objects when you don't need to sample values (depth/stencil buffer) 
	// and textures when you do need to sample values (like the color buffer).
	glGenRenderbuffers(1, &mFramebufferDepthStencil);
	glBindRenderbuffer(GL_RENDERBUFFER, mFramebufferDepthStencil);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, mApplication->GetWidth(), mApplication->GetHeight()); // Create a depth/stencil renderbuffer object.
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	//Attach the renderbuffer as the depth/stencil buffer
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, mFramebufferDepthStencil);

	// Check if the framebuffer is complete. If it is, all subsequent rendering operations will render to the attachments of the currently bound framebuffer.
	// But, since our framebuffer is not the default framebuffer, it will not affect the visual output on our window. To draw on the window itself we need to go back to the default framebuffer
	// with glBindFramebuffer(GL_FRAMEBUFFER, 0).
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		throw GameException("Framebuffer incomplete");
	}
	//Go back to the default framebuffer.
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	//---- CONTAINER ----//
	//Generate VBOs and VAO.
	glGenVertexArrays(1, &mContainerVAO);
	glGenBuffers(1, &mContainerVBO);

	//Bind VAO and buffers, and fill in buffer data
	glBindVertexArray(mContainerVAO);
	glBindBuffer(GL_ARRAY_BUFFER, mContainerVBO);
	glBufferData(GL_ARRAY_BUFFER, mVerticesContainer.size() * sizeof(GLfloat), &mVerticesContainer[0], GL_STATIC_DRAW);
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

	//-----QUAD------//
	//Generate VBOs and VAO.
	glGenVertexArrays(1, &mQuadVAO);
	glGenBuffers(1, &mQuadVBO);

	//Bind VAO and buffers, and fill in buffer data
	glBindVertexArray(mQuadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, mQuadVBO);
	glBufferData(GL_ARRAY_BUFFER, mVerticesQuad.size() * sizeof(GLfloat), &mVerticesQuad[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
	

	//Unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	mShaderContainer = Shader("shaders/container.vert", "shaders/container.frag");
	mShaderQuad = Shader("shaders/quad.vert", "shaders/quad.frag");
	mShaderInvert = Shader("shaders/quad.vert", "shaders/invert.frag");
	mShaderGrayscale = Shader("shaders/quad.vert", "shaders/grayscale.frag");
	mShaderSharpen = Shader("shaders/quad.vert", "shaders/sharpen.frag");
	mShaderBlur = Shader("shaders/quad.vert", "shaders/blur.frag");
	mShaderEdgeDetection = Shader("shaders/quad.vert", "shaders/edge_detection.frag");
}

void FrambuffersComponent::Draw(float DeltaSeconds)
{
	glBindFramebuffer(GL_FRAMEBUFFER, mFBO); //Bind to our framebuffer for off-screen rendering.

	glClearColor(0.1f, 0.1f, 0.1f, 0.1f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);


	mShaderContainer.UseProgram();
	glBindVertexArray(mContainerVAO);
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

	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetViewMatrix()));
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetProjectionMatrix()));

	// MATERIAL PROPERTIES
	GLint matDiffuseLocation = glGetUniformLocation(mShaderContainer.Program(), "material.diffuse");
	GLint matSpecularLocation = glGetUniformLocation(mShaderContainer.Program(), "material.specular");
	GLint matShineLocation = glGetUniformLocation(mShaderContainer.Program(), "material.shininess");
	glUniform1i(matDiffuseLocation, 0);
	glUniform1i(matSpecularLocation, 1);
	glUniform1f(matShineLocation, 8.0f);

	


	for (size_t i = 0; i < mCubePositions.size(); ++i)
	{
		glm::mat4 model;
		model = glm::translate(glm::mat4(), mCubePositions[i]);
		float angle = 20.0f * i;
		model = glm::rotate(model, glm::radians(angle), glm::vec3(0.2f, 0.5f, 0.5f));

		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0); //Back to the default framebuffer so we can actually draw to the output window
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glDisable(GL_DEPTH_TEST);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //Uncomment to see that we're actually rendering a quad in the final output window.

	// UNCOMMENT AN EFFECT TO USE IT.
	//mShaderQuad.UseProgram();
	//mShaderInvert.UseProgram();
	//mShaderGrayscale.UseProgram();
	//mShaderSharpen.UseProgram();
	//mShaderBlur.UseProgram();
	mShaderEdgeDetection.UseProgram();

	glBindVertexArray(mQuadVAO);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mFramebufferColorTexture);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glUseProgram(0);
	glBindVertexArray(0);
}
