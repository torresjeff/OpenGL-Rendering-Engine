#include "TextureApplication.h"
#include <SOIL/SOIL.h>
#include "InputHandler.h"

TextureApplication::TextureApplication(std::string name, int width, int height)
	: Application(name, width, height)
{}

void TextureApplication::Initialize()
{
	mTextureComponent = new TextureComponent(*this);
	mComponents.push_back(mTextureComponent);

	glEnable(GL_DEPTH_TEST);
	glfwSetKeyCallback(window, TextureDemoCallback);

	Application::Initialize();
}

void TextureApplication::Draw(float DeltaSeconds)
{
	glClearBufferfv(GL_COLOR, 0, &mBackgroundColor[0]);
	glClear(GL_DEPTH_BUFFER_BIT);


	Application::Draw(DeltaSeconds);

	glfwSwapBuffers(window);
}
