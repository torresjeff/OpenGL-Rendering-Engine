#include "PhongLightingApplication.h"

PhongLightingApplication::PhongLightingApplication(std::string name, int width, int height)
	: FirstPersonApplication(name, width, height)
{}

PhongLightingApplication::~PhongLightingApplication()
{
	delete mPhongLightingComponent;
}

void PhongLightingApplication::Initialize()
{
	FirstPersonApplication::Initialize();
	
	mPhongLightingComponent = new PhongLightingComponent(*this, *mCamera);
	mComponents.push_back(mPhongLightingComponent);
	
	glEnable(GL_DEPTH_TEST);
	Application::Initialize();
}
