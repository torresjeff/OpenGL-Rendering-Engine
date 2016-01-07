#include "DepthTestingApplication.h"

DepthTestingApplication::DepthTestingApplication(std::string name, int width, int height)
	: FirstPersonApplication(name, width, height)
{}

DepthTestingApplication::~DepthTestingApplication()
{
	delete mLightMapsComponent;
}

void DepthTestingApplication::Initialize()
{
	FirstPersonApplication::Initialize();

	mLightMapsComponent = new DepthTestingComponent(*this, *mCamera);
	mComponents.push_back(mLightMapsComponent);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_NOTEQUAL); //The depth test passes if the new depth value is not equal to the value already stored
	//glDepthMask(GL_FALSE); //Disable writing to the depth buffer, default is GL_TRUE

	Application::Initialize();
}
