#include "CoordinateSystemsApplication.h"
#include <SOIL/SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


CoordinateSystemsApplication::CoordinateSystemsApplication(std::string name, int width, int height)
	: Application(name, width, height)
{}

void CoordinateSystemsApplication::Initialize()
{
	mCoordinateSystemDemo = new CoordinateSystemsComponent(*this);
	mComponents.push_back(mCoordinateSystemDemo);

	glEnable(GL_DEPTH_TEST);
	Application::Initialize();
}

void CoordinateSystemsApplication::Draw(float DeltaSeconds)
{
	glClearBufferfv(GL_COLOR, 0, &mBackgroundColor[0]);
	glClear(GL_DEPTH_BUFFER_BIT);

	Application::Draw(DeltaSeconds);

	glfwSwapBuffers(window);
}

