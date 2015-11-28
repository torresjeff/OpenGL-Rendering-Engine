#include "ShaderDemo.h"

ShaderDemo::ShaderDemo(std::string name, int WIDTH, int HEIGHT)
	: Application(name, WIDTH, HEIGHT)
{}

void ShaderDemo::Run()
{
	std::vector<float> color{ 0.2f, 0.3f, 0.3f, 1.0f }; //Background color

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearBufferfv(GL_COLOR, 0, &color[0]);





		glfwSwapBuffers(window);
	}
}
