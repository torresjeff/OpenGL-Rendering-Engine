#pragma once

#include "Camera.h"

class FirstPersonCamera : public Camera
{
public:
	FirstPersonCamera(Application& application);
	FirstPersonCamera(Application& application, float fieldOfView, float aspectRatio, float nearPlane, float farPlane);

	virtual void Initialize() override;
	virtual void Update(float DeltaSeconds) override;
	static const float DefaultSpeed;
protected:
	float mSpeed;

private:
	double mLastCursorX, mLastCursorY;
};
