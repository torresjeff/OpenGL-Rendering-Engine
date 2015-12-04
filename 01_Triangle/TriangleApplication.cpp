#include "TriangleApplication.h"

TriangleApplication::TriangleApplication(std::string name, int width, int height)
	: Application(name, width, height)
{}

void TriangleApplication::Initialize()
{
	mTriangleComponent = new TriangleComponent(*this);
	mComponents.push_back(mTriangleComponent);

	Application::Initialize();
}

void TriangleApplication::Draw(float DeltaSeconds)
{
	glClearBufferfv(GL_COLOR, 0, &mBackgroundColor[0]);

	Application::Draw(DeltaSeconds);

	glfwSwapBuffers(window);
}
