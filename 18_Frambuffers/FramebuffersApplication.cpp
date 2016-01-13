#include "FramebuffersApplication.h"

FramebuffersApplication::FramebuffersApplication(std::string name, int width, int height)
	: FirstPersonApplication(name, width, height)
{}

FramebuffersApplication::~FramebuffersApplication()
{
	delete mLightMapsComponent;
}

void FramebuffersApplication::Initialize()
{
	FirstPersonApplication::Initialize();

	mLightMapsComponent = new FrambuffersComponent(*this, *mCamera);
	mComponents.push_back(mLightMapsComponent);

	glEnable(GL_DEPTH_TEST);

	Application::Initialize();
}
