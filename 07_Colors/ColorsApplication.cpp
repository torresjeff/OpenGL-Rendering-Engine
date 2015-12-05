#include "ColorsApplication.h"

ColorsApplication::ColorsApplication(std::string name, int width, int height)
	: Application(name, width, height)
{}

ColorsApplication::~ColorsApplication()
{
	if (mColorComponent)
	{
		delete mColorComponent;
		mColorComponent = nullptr;
	}
}

void ColorsApplication::Initialize()
{
	mColorComponent = new ColorsComponent(*this);
	mComponents.push_back(mColorComponent);
	
	glEnable(GL_DEPTH_TEST);
	Application::Initialize();
}

void ColorsApplication::Draw(float DeltaSeconds)
{
	glClearBufferfv(GL_COLOR, 0, &mBackgroundColor[0]);
	glClear(GL_DEPTH_BUFFER_BIT);

	Application::Draw(DeltaSeconds);

	glfwSwapBuffers(window);
}
