#include "TransformationApplication.h"
#include <SOIL/SOIL.h>

TransformationApplication::TransformationApplication(std::string name, int width, int height)
	: Application(name, width, height)
{}

void TransformationApplication::Initialize()
{
	glEnable(GL_DEPTH_TEST);

	mTransformationComponent = new TransformationComponent(*this);
	mComponents.push_back(mTransformationComponent);

	Application::Initialize();
}

void TransformationApplication::Draw(float DeltaSeconds)
{
	glClearBufferfv(GL_COLOR, 0, &mBackgrounColor[0]);
	glClear(GL_DEPTH_BUFFER_BIT);

	Application::Draw(DeltaSeconds);

	glfwSwapBuffers(window);

}
