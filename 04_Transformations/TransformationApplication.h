#pragma once

#include <Common/Common.h>
#include "TransformationComponent.h"

class TransformationApplication : public Application
{
public:
	TransformationApplication(std::string name, int width, int height);
	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
private:
	TransformationComponent* mTransformationComponent;
	std::vector<GLfloat> mBackgrounColor{ 0.2f, 0.3f, 0.3f, 1.0f };
};


