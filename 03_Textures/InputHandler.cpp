#include <glm/common.hpp>
#include "InputHandler.h"
#include "TextureDemo.h"

void TextureDemoCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
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
	case GLFW_KEY_UP:
		switch (action)
		{
		case GLFW_RELEASE:
			break;
		default:
			cout << "Key up pressed, interpolation=" << interpolation << "\n";
			interpolation = glm::clamp(interpolation + 0.01f, 0.0f, 1.0f);
			break;
		}
		break;
	case GLFW_KEY_DOWN:
		switch (action)
		{
		case GLFW_RELEASE:
			break;
		default:
			cout << "Key down pressed, interpolation=" << interpolation << "\n";
			interpolation = glm::clamp(interpolation - 0.01f, 0.0f, 1.0f);
			break;
		}
		break;
	}
}

