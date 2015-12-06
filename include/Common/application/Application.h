#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>
#include "../exceptions/GameException.h"
#include "InputHandler.h"
#include "GameComponent.h"
#include "DrawableGameComponent.h"

using std::cout;
using std::endl;

class Application
{
public:
	Application(std::string name, int width, int height);
	virtual ~Application();

public:
	virtual void Run();
	virtual void Update(float DeltaSeconds);
	virtual void Draw(float DeltaSeconds);

	void AddComponent(GameComponent* component);
	
	//Getters/Setters
	void SetKeyCallback(GLFWkeyfun callback);
	inline int GetWidth() { return mWidth; }
	inline int GetHeight() { return mHeight; }
	inline GLFWwindow* GetWindow() const { return window; }
	float GetAspectRatio();
protected:
	virtual void InitializeGlfw();
	virtual void InitializeGlew();
	virtual void Initialize();
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	static void WindowResizeCallback(GLFWwindow* window, int width, int height);
protected:
	GLFWwindow* window;
	std::string mName;
	int mWidth;
	int mHeight;
	std::vector<GameComponent*> mComponents;
};
