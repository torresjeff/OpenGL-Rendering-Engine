#include "StencilTestingApplication.h"

// http://www.learnopengl.com/#!Advanced-OpenGL/Stencil-testing
/*
 * When using stencil buffers you can get as crazy as you like, but the general outline is usually as follows:
 * - Enable writing to the stencil buffer.	
 * - Render objects, updating the content of the stencil buffer.
 * - Disable writing to the stencil buffer.
 * - Render (other) objects, this time discarding certain fragments based on the content of the stencil buffer.
*/

StencilTestingApplication::StencilTestingApplication(std::string name, int width, int height)
	: FirstPersonApplication(name, width, height)
{}

StencilTestingApplication::~StencilTestingApplication()
{
	delete mLightMapsComponent;
}

void StencilTestingApplication::Initialize()
{
	FirstPersonApplication::Initialize();

	mLightMapsComponent = new StencilTestingComponent(*this, *mCamera);
	mComponents.push_back(mLightMapsComponent);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_STENCIL_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	//The mask specified is ANDed with the stencil value about to be written to the buffer.
	//glStencilMask(0xFF); //Each bit is written to the stencil buffer as is. 
	//glStencilMask(0x00); //Each bit ends up as 0 in the stencil buffer (disables writing).  Equivalent to glDepthMask(GL_FALSE).

	//glStencilFunc: describes what we should do with the content of the stencil buffer and how we should determine if a test passes or fails.
	// 1st param: func. Sets the stencil test function. The test function is applied to the stored stencil value and the reference value (second parameter) and determines wheter the test is passed or not.
	//			eg. if this value is set to GL_LESS, then the depth test passes when: (ref & mask) < (stencil & mask)
	// 2nd param: ref. A value to compare the stencil value to using the test function.
	// 3rd param: mask. A bitwise AND operation is performed on the stencil value already stored and the reference value (2nd param) with this mask value
	//			 BEFORE comparing them (using GL_EQUAL or whatever was specified in the 1st param).
	//glStencilFunc(GL_EQUAL, 1, 0xFF); // The stencil test passes when: (1 & 0xFF) == (stencil & 0xFF), in other wods when (stencil & 0xFF) is equal to 1
	// If you don't want stencils with a value lower than 2 to be affected, you would use: glStencilFunc(GL_GEQUAL, 2, 0xFF);
	
	//glStencilOp: describes how we should update the stencil buffer based on the tests passing or failing.
	// 1st parameter: sfail. Action to take if the stencil test fails.
	// 2nd parameter: dpfail. Action to take if the stencil test passes BUT depth test fails.
	// 3rd parameter: dppas. Action to take if both the stencil and depth test pass.
	// Possible values are: GL_KEEP (the currently stored value is kept), GL_REPLACE (the stencil value is replaced with the reference value set with glStencilFunc(.., ref, ..)
	//glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP); //default values. Does not update the stencil value.
	Application::Initialize();
}

void StencilTestingApplication::Draw(float DeltaSeconds)
{
	glClear(GL_STENCIL_BUFFER_BIT);

	FirstPersonApplication::Draw(DeltaSeconds);
}
