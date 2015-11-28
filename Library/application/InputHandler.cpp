#include "InputHandler.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
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