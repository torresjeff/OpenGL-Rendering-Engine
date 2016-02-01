#include "AdvancedDataApplication.h"

AdvancedDataApplication::AdvancedDataApplication(std::string name, int width, int height)
	: FirstPersonApplication(name, width, height)
{}

AdvancedDataApplication::~AdvancedDataApplication()
{
	delete mFaceCullingComponent;
}

void AdvancedDataApplication::Initialize()
{
	FirstPersonApplication::Initialize();

	mFaceCullingComponent = new AdvancedDataComponent(*this, *mCamera);
	mComponents.push_back(mFaceCullingComponent);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	Application::Initialize();
}
