#include "MaterialsApplication.h"

MaterialsApplication::MaterialsApplication(std::string name, int width, int height)
	: FirstPersonApplication(name, width, height)
{}

MaterialsApplication::~MaterialsApplication()
{
	delete mMaterialsComponent;
}

void MaterialsApplication::Initialize()
{
	FirstPersonApplication::Initialize();

	mMaterialsComponent = new MaterialsComponent(*this, *mCamera);
	mComponents.push_back(mMaterialsComponent);

	glEnable(GL_DEPTH_TEST);
	Application::Initialize();
}
