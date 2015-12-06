#pragma once

#include "Camera.h"

class FirstPersonCamera : public Camera
{
public:
	FirstPersonCamera(Application& application);
	FirstPersonCamera(Application& application, float fieldOfView, float aspectRatio, float nearPlane, float farPlane);

	virtual void Initialize() override;
	virtual void Update(float DeltaSeconds) override;
	
	float GetSpeed();
	void SetSpeed(float speed);
	float GetMouseSensitivity();
	void SetMouseSensitivity(float mouseSensitivity);
	
	static const float DefaultSpeed;
	static const float DefualtMouseSensitivity;
	static const float DefaultRotationRate;
protected:
	float mSpeed;
	float mMouseSensitivity;
	
private:
	double mLastCursorX, mLastCursorY;
	float mRotationRate;
};
