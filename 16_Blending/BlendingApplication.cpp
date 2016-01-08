#include "BlendingApplication.h"

BlendingApplication::BlendingApplication(std::string name, int width, int height)
	: FirstPersonApplication(name, width, height)
{}

BlendingApplication::~BlendingApplication()
{
	delete mLightMapsComponent;
}

void BlendingApplication::Initialize()
{
	FirstPersonApplication::Initialize();

	mLightMapsComponent = new BlendingComponent(*this, *mCamera);
	mComponents.push_back(mLightMapsComponent);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	Application::Initialize();
}
