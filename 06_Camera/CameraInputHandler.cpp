#include "CameraInputHandler.h"

//TODO: remove extern for global variables
extern bool keys[1024];
extern GLfloat lastX, lastY;
extern GLfloat pitch, yaw;
extern glm::vec3 cameraFront;
extern GLfloat fov;

bool firstTime = true;

void CameraKeyCallback(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	switch (action)
	{
	case GLFW_PRESS:
		keys[key] = true;
		break;
	case GLFW_RELEASE:
		keys[key] = false;
		break;
	}
	
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

void MouseCallback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstTime)
	{
		cout << "Mouse first\n";
		lastX = xpos;
		lastY = ypos;
		firstTime = false;
	}

	GLfloat xOffset = xpos - lastX;
	GLfloat yOffset = lastY - ypos; // Reversed since y-coordinates range from bottom to top
	lastX = xpos;
	lastY = ypos;

	GLfloat sensitivity = 0.05f;
	xOffset *= sensitivity;
	yOffset *= sensitivity;

	yaw += xOffset;
	pitch += yOffset;

	if (pitch > 89.0f)
	{
		pitch = 89.0f;
	}
	if (pitch < -89.0f)
	{
		pitch = -89.0f;
	}

	//Calculate the actual direction vector from the resulting pitch and yaw value. Done with Euler angles.
	// More about Euler angles: https://www.youtube.com/watch?v=zZM2uUkEoFw
	glm::vec3 front;
	front.x = glm::cos(glm::radians(pitch)) * glm::cos(glm::radians(yaw));
	front.y = glm::sin(glm::radians(pitch));
	front.z = glm::cos(glm::radians(pitch)) * glm::sin(glm::radians(yaw));
	cameraFront = front;
}

void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	//yoffset value represents the amount we scrolled vertically
	GLfloat speed = 10.0f;
	if (fov >= 1.0f && fov <= 90.0f)
	{
		fov -= yoffset * speed;
	}
	if (fov < 1.0f)
	{
		fov = 1.0f;
	}
	if (fov > 90.0f)
	{
		fov = 90.0f;
	}
}
