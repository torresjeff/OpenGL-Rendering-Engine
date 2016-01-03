#pragma once

#include "Application.h"
#include "FirstPersonCamera.h"

class FirstPersonApplication : public Application
{
public:
	FirstPersonApplication(std::string name, int width, int height);
	virtual ~FirstPersonApplication();

	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
protected:
	std::vector<GLfloat> mBackgroundColor{ 0.2f, 0.3f, 0.3f, 1.0f };
	FirstPersonCamera* mCamera;
};