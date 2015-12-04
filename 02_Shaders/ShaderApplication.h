#pragma once

//#include <Common/application/Application.h>
#include <Common/Common.h>
#include "ShaderComponent.h"

class ShaderApplication : public Application
{
public:
	ShaderApplication(std::string name, int WIDTH, int HEIGHT);

public:
	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;

	ShaderComponent* mShaderComponent;
private:
	std::vector<GLfloat> mBackgroundColor{ 0.2f, 0.3f, 0.3f, 1.0f };
};
