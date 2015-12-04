#pragma once

#include <Common/Common.h>
#include "TriangleComponent.h"

class TriangleApplication : public Application
{
public:
	TriangleApplication(std::string name, int WIDTH, int HEIGHT);

public:
	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;

	TriangleComponent* mTriangleComponent;
private:
	std::vector<GLfloat> mBackgroundColor{ 0.2f, 0.3f, 0.3f, 1.0f };
};
