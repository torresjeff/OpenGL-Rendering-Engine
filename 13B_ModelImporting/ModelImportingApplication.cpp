#include "ModelImportingApplication.h"

ModelImportingApplication::ModelImportingApplication(std::string name, int width, int height)
	: FirstPersonApplication(name, width, height)
{}

ModelImportingApplication::~ModelImportingApplication()
{
	delete mModelComponent;
}


void ModelImportingApplication::Initialize()
{
	FirstPersonApplication::Initialize();

	//mModelComponent = new ModelImportingComponent(*this, *mCamera, "res/nanosuit.obj", Shader("shaders/model.vert", "shaders/model.frag"));
	mModelComponent = new ModelImportingComponent(*this, *mCamera);
	mComponents.push_back(mModelComponent);

	glEnable(GL_DEPTH_TEST);
	Application::Initialize();
}
