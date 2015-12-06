#include "FirstPersonCamera.h"


const float FirstPersonCamera::DefaultSpeed = 10.0f;


FirstPersonCamera::FirstPersonCamera(Application& application)
	: Camera(application), mSpeed(DefaultSpeed), mLastCursorX(0.0), mLastCursorY(0.0)
{}

FirstPersonCamera::FirstPersonCamera(Application& application, float fieldOfView, float aspectRatio, float nearPlane, float farPlane)
	: Camera(application, fieldOfView, aspectRatio, nearPlane, farPlane), mSpeed(DefaultSpeed), mLastCursorX(0.0), mLastCursorY(0.0)
{}

void FirstPersonCamera::Initialize()
{
	Camera::Initialize();
	glfwGetCursorPos(mApplication->GetWindow(), &mLastCursorX, &mLastCursorY);
}

void FirstPersonCamera::Update(float DeltaSeconds)
{
	cout << "FPSCam Update: postion=" << mPosition.x << " " << mPosition.y << " " << mPosition.z << "\n";
	GLFWwindow* window = mApplication->GetWindow();
	
	glm::vec2 movementAmount;

	if (glfwGetKey(window, GLFW_KEY_W))
	{
		movementAmount.y = 1.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_S))
	{
		movementAmount.y = -1.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_A))
	{
		movementAmount.x = -1.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_D))
	{
		movementAmount.x = 1.0f;
	}

	glm::vec2 movement = movementAmount * mSpeed * DeltaSeconds;

	glm::vec3 strafe = mRight * movement.x;
	mPosition += strafe;
	glm::vec3 forward = mDirection * movement.y; 
	mPosition += forward;

	double x, y;
	glfwGetCursorPos(window, &x, &y);

	//TODO: rotations

	mLastCursorX = x;
	mLastCursorY = y;

	Camera::Update(DeltaSeconds);
}

float FirstPersonCamera::GetSpeed()
{
	return mSpeed;
}

void FirstPersonCamera::SetSpeed(float speed)
{
	mSpeed = speed;
}
