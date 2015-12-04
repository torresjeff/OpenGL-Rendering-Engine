#include "Application.h"

Application::Application(std::string name, int width, int height)
{
	this->mWidth = width;
	this->mHeight = height;
}

Application::~Application()
{
	glfwTerminate();
}

void Application::Update(float DeltaSeconds)
{
	for (auto component : mComponents)
	{
		if (component->Enabled())
		{
			component->Update(DeltaSeconds);
		}
	}
}

void Application::Draw(float DeltaSeconds)
{
	for (auto component : mComponents)
	{
		DrawableGameComponent* drawableComponent = dynamic_cast<DrawableGameComponent*>(component);
		if (drawableComponent != nullptr && drawableComponent->IsVisible())
		{
			drawableComponent->Draw(DeltaSeconds);
		}
	}
}

void Application::AddComponent(GameComponent * component)
{
	mComponents.push_back(component);
}

void Application::InitializeGlfw()
{
	if (glfwInit() == GL_FALSE)
	{
		cout << "glfwInit() failed" << endl;
		throw GameException("glfwInit() failed");
	}

	window = glfwCreateWindow(mWidth, mHeight, mName.c_str(), nullptr, nullptr);

	if (!window)
	{
		cout << "glfwCreateWindow() failed" << endl;
		glfwTerminate();
		return;
	}

	glfwSetKeyCallback(window, &key_callback);
	glfwMakeContextCurrent(window);
}

void Application::InitializeGlew()
{
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		cout << "glewInit() failed" << endl;
		glfwTerminate();
		return;
	}

	glViewport(0, 0, mWidth, mHeight);
}

void Application::Initialize()
{
	for (GameComponent* component : mComponents)
	{
		component->Initialize();
	}
}

void Application::key_callback(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	switch (key)
	{
	case GLFW_KEY_ESCAPE:
		switch (action)
		{
		case GLFW_PRESS:
			glfwSetWindowShouldClose(window, GL_TRUE);
			break;
		}
		break;
	}
}

void Application::Run()
{
	InitializeGlfw();
	InitializeGlew();
	Initialize();

	float CurrentTime = 0.0f;
	float LastTime = (float)glfwGetTime();
	float DeltaSeconds = 0.0f;

	//glEnable(GL_DEPTH_TEST);
	
	while (!glfwWindowShouldClose(window))
	{
		CurrentTime = (float)glfwGetTime();
		DeltaSeconds = CurrentTime - LastTime;
		LastTime = CurrentTime;

		Update(DeltaSeconds);
		Draw(DeltaSeconds);

		//glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void Application::SetKeyCallback(GLFWkeyfun callback)
{
	glfwSetKeyCallback(window, callback);
}

