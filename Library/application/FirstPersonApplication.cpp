#include "FirstPersonApplication.h"

FirstPersonApplication::FirstPersonApplication(std::string name, int width, int height)
	: Application(name, width, height)
{}

FirstPersonApplication::~FirstPersonApplication()
{
	delete mCamera;
}

void FirstPersonApplication::Initialize()
{
	mCamera = new FirstPersonCamera(*this);
	mComponents.push_back(mCamera);
}

void FirstPersonApplication::Draw(float DeltaSeconds)
{
	glClearBufferfv(GL_COLOR, 0, &mBackgroundColor[0]);
	glClear(GL_DEPTH_BUFFER_BIT);

	Application::Draw(DeltaSeconds);

	glfwSwapBuffers(window);
}
