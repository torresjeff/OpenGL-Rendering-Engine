#include "FaceCullingApplication.h"

/*
 * Fly inside a cube to see that the inner faces are not rendered.
 **/

FaceCullingApplication::FaceCullingApplication(std::string name, int width, int height)
	: FirstPersonApplication(name, width, height)
{}

FaceCullingApplication::~FaceCullingApplication()
{
	delete mFaceCullingComponent;
}

void FaceCullingApplication::Initialize()
{
	FirstPersonApplication::Initialize();

	mFaceCullingComponent = new FaceCullingComponent(*this, *mCamera);
	mComponents.push_back(mFaceCullingComponent);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE); // Enable face culling, by default the front facing (visible) triangle order is counter clockwise.
	//glCullFace(GL_FRONT);  // Allows us to specify which faces we want to call. Possible values: GL_FRONT, GL_BACK, GL_FRONT_AND_BACK. Default is GL_BACK (back-face culling).
	//glFrontFace(GL_CW); // Tell OpenGL the winding order we want to use for our front face. Possible values: GL_CW (clockwise), GL_CCW (counter-clockwise). Default is GL_CCW.

	Application::Initialize();
}
