#include "FirstPersonCamera.h"


const float FirstPersonCamera::DefaultSpeed = 10.0f;
const float FirstPersonCamera::DefualtMouseSensitivity = 1.0f;
const float FirstPersonCamera::DefaultRotationRate = 10.0f;

FirstPersonCamera::FirstPersonCamera(Application& application)
	: Camera(application), mSpeed(DefaultSpeed), mMouseSensitivity(DefualtMouseSensitivity), mRotationRate(DefaultRotationRate), mLastCursorX(0.0), mLastCursorY(0.0)
{}

FirstPersonCamera::FirstPersonCamera(Application& application, float fieldOfView, float aspectRatio, float nearPlane, float farPlane)
	: Camera(application, fieldOfView, aspectRatio, nearPlane, farPlane), mSpeed(DefaultSpeed), mMouseSensitivity(DefualtMouseSensitivity), mRotationRate(DefaultRotationRate),
	mLastCursorX(0.0), mLastCursorY(0.0)
{}

void FirstPersonCamera::Initialize()
{
	Camera::Initialize();
	glfwGetCursorPos(mApplication->GetWindow(), &mLastCursorX, &mLastCursorY);
}

void FirstPersonCamera::Update(float DeltaSeconds)
{
	/*cout << "FPSCam Update: postion=" << mPosition.x << " " << mPosition.y << " " << mPosition.z << "\n";
	cout << "FPSCam Update: direction=" << mDirection.x << " " << mDirection.y << " " << mDirection.z << "\n";*/
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

	double x, y;
	glfwGetCursorPos(window, &x, &y);

	glm::vec2 rotationAmount = glm::vec2(0.0f);
	
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT))
	{
		rotationAmount.x = (mLastCursorX - x) * mMouseSensitivity;
		rotationAmount.y = (mLastCursorY - y) * mMouseSensitivity;
	}

	mLastCursorX = x;
	mLastCursorY = y;

	glm::vec2 rotationVector = rotationAmount * mRotationRate * DeltaSeconds;
	glm::mat4 transform;
	transform = glm::rotate(glm::mat4(), glm::radians(rotationVector.x), glm::vec3(0.0f, 1.0f, 0.0f));
	transform = glm::rotate(transform, glm::radians(rotationVector.y), mRight);

	ApplyRotation(transform);

	glm::vec2 movement = movementAmount * mSpeed * DeltaSeconds;
	glm::vec3 strafe = mRight * movement.x;
	mPosition += strafe;
	glm::vec3 forward = mDirection * movement.y; 
	mPosition += forward;

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

float FirstPersonCamera::GetMouseSensitivity()
{
	return mMouseSensitivity;
}

void FirstPersonCamera::SetMouseSensitivity(float mouseSensitivity)
{
	mMouseSensitivity = mouseSensitivity;
}
