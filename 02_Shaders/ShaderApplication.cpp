#include "ShaderApplication.h"
#include <glm/glm.hpp>

ShaderApplication::ShaderApplication(std::string name, int width, int height)
	: Application(name, width, height)
{}

void ShaderApplication::Initialize()
{
	mShaderComponent = new ShaderComponent(*this);
	mComponents.push_back(mShaderComponent);

	Application::Initialize();
}

void ShaderApplication::Draw(float DeltaSeconds)
{
	glClearBufferfv(GL_COLOR, 0, &mBackgroundColor[0]);

	Application::Draw(DeltaSeconds);

	glfwSwapBuffers(window);
}
