#include "LightMapsApplication.h"

LightMapsApplication::LightMapsApplication(std::string name, int width, int height)
	: FirstPersonApplication(name, width, height)
{}

LightMapsApplication::~LightMapsApplication()
{
	delete mLightMapsComponent;
}

void LightMapsApplication::Initialize()
{
	FirstPersonApplication::Initialize();

	mLightMapsComponent = new LightMapsComponent(*this, *mCamera);
	mComponents.push_back(mLightMapsComponent);

	glEnable(GL_DEPTH_TEST);
	Application::Initialize();
}
