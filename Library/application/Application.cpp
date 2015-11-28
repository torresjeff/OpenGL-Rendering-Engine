#include "Application.h"

Application::Application(std::string name, int WIDTH, int HEIGHT)
{
	InitializeGlfw(name, WIDTH, HEIGHT);
	InitializeGlew(WIDTH, HEIGHT);

	this->width = WIDTH;
	this->height = HEIGHT;
}

Application::~Application()
{
	glfwTerminate();
}

void Application::InitializeGlfw(std::string name, int WIDTH, int HEIGHT)
{
	if (glfwInit() == GL_FALSE)
	{
		cout << "glfwInit() failed" << endl;
		throw GameException("glfwInit() failed");
	}

	window = glfwCreateWindow(WIDTH, HEIGHT, name.c_str(), nullptr, nullptr);

	if (!window)
	{
		cout << "glfwCreateWindow() failed" << endl;
		glfwTerminate();
		return;
	}

	glfwSetKeyCallback(window, &key_callback);
	glfwMakeContextCurrent(window);
}

void Application::InitializeGlew(int WIDTH, int HEIGHT)
{
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		cout << "glewInit() failed" << endl;
		glfwTerminate();
		return;
	}

	glViewport(0, 0, WIDTH, HEIGHT);
}

void Application::Run()
{
	std::vector<float> color{ 0.2f, 0.3f, 0.3f, 1.0f }; //Background color

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearBufferfv(GL_COLOR, 0, &color[0]);



		glfwSwapBuffers(window);
	}
}

void Application::SetKeyCallback(GLFWkeyfun callback)
{
	glfwSetKeyCallback(window, callback);
}

