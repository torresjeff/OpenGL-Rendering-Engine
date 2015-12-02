#pragma once

#include <Common/Common.h>
#include "CameraDemo.h"

class CameraApplication : public Application
{
public:
	CameraApplication(std::string name, int width, int height);
	virtual ~CameraApplication();
protected:
	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
private:
	CameraDemo* mCameraDemo;
	std::vector<GLfloat> mBackgroundColor;//{ 0.2f, 0.3f, 0.3f, 1.0f }; //Background color
};


