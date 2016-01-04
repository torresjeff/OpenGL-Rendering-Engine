#include "LightCastersApplication.h"

LightCastersApplication::LightCastersApplication(std::string name, int width, int height)
	: FirstPersonApplication(name, width, height)
{}

LightCastersApplication::~LightCastersApplication()
{
	delete mLightMapsComponent;
}

void LightCastersApplication::Initialize()
{
	FirstPersonApplication::Initialize();

	mLightMapsComponent = new LightCastersComponent(*this, *mCamera);
	mComponents.push_back(mLightMapsComponent);

	glEnable(GL_DEPTH_TEST);
	Application::Initialize();
}
