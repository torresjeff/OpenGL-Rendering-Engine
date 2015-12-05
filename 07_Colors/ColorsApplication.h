#pragma once

#include <Common/Common.h>
#include "ColorsComponent.h"

class ColorsApplication : public Application
{
public:
	ColorsApplication(std::string name, int width, int height);
	virtual ~ColorsApplication();

	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
private:
	std::vector<GLfloat> mBackgroundColor{ 0.2f, 0.3f, 0.3f, 1.0f };
	ColorsComponent* mColorComponent;
};
