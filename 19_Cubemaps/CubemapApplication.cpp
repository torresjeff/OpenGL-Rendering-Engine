#include "CubemapApplication.h"

CubemapApplication::CubemapApplication(std::string name, int width, int height)
	: FirstPersonApplication(name, width, height)
{}

CubemapApplication::~CubemapApplication()
{
	delete mFaceCullingComponent;
}

void CubemapApplication::Initialize()
{
	FirstPersonApplication::Initialize();

	mFaceCullingComponent = new CubemapComponent(*this, *mCamera);
	mComponents.push_back(mFaceCullingComponent);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	Application::Initialize();
}
