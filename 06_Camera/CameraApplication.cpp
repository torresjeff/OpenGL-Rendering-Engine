#include "CameraApplication.h"
#include <SOIL/SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


CameraApplication::CameraApplication(std::string name, int width, int height)
	: Application(name, width, height)
{
}

CameraApplication::~CameraApplication()
{
	if (mCameraDemo)
	{
		delete mCameraDemo;
	}
}

void CameraApplication::Initialize()
{
	mCameraDemo = new CameraDemo(*this);
	mComponents.push_back(mCameraDemo);

	mBackgroundColor = { 0.2f, 0.3f, 0.3f, 1.0f };

	glEnable(GL_DEPTH_TEST);
	Application::Initialize();
}

void CameraApplication::Draw(float DeltaSeconds)
{
	glClearBufferfv(GL_COLOR, 0, &mBackgroundColor[0]);
	glClear(GL_DEPTH_BUFFER_BIT);

	Application::Draw(DeltaSeconds);

	glfwSwapBuffers(window);
}
