#include "UniformBlockApplication.h"

UniformBlockApplication::UniformBlockApplication(std::string name, int width, int height)
	: FirstPersonApplication(name, width, height)
{}

UniformBlockApplication::~UniformBlockApplication()
{
	delete mFaceCullingComponent;
}

void UniformBlockApplication::Initialize()
{
	FirstPersonApplication::Initialize();

	mFaceCullingComponent = new UniformBlockComponent(*this, *mCamera);
	mComponents.push_back(mFaceCullingComponent);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	Application::Initialize();
}
