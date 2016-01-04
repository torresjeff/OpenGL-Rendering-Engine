#include "ModelImportingApplication.h"

ModelImportingApplication::ModelImportingApplication(std::string name, int width, int height)
	: FirstPersonApplication(name, width, height)
{}

ModelImportingApplication::~ModelImportingApplication()
{
	delete mLightMapsComponent;
}

void ModelImportingApplication::Initialize()
{
	FirstPersonApplication::Initialize();

	mLightMapsComponent = new ModelImportingComponent(*this, *mCamera);
	mComponents.push_back(mLightMapsComponent);

	glEnable(GL_DEPTH_TEST);
	Application::Initialize();
}
