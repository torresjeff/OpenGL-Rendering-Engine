#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>
#include "../exceptions/GameException.h"

using std::cout;
using std::endl;

class Application
{
public:
	Application(std::string name, int WIDTH, int HEIGHT);
	virtual ~Application();

public:
	virtual void Run();

	void SetKeyCallback(GLFWkeyfun callback);

	inline int GetWidth() { return width; }
	inline int GetHeight() { return height; }
protected:
	void InitializeGlfw(std::string name, int WIDTH, int HEIGHT);
	void InitializeGlew(int WIDTH, int HEIGHT);
protected:
	GLFWwindow* window;
	int width;
	int height;
};
