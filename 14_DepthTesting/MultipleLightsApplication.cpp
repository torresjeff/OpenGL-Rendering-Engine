#include "MultipleLightsApplication.h"

MultipleLightsApplication::MultipleLightsApplication(std::string name, int width, int height)
	: FirstPersonApplication(name, width, height)
{}

MultipleLightsApplication::~MultipleLightsApplication()
{
	delete mLightMapsComponent;
}

void MultipleLightsApplication::Initialize()
{
	FirstPersonApplication::Initialize();

	mLightMapsComponent = new MultipleLightsComponent(*this, *mCamera);
	mComponents.push_back(mLightMapsComponent);

	glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_NOTEQUAL);
	Application::Initialize();
}
