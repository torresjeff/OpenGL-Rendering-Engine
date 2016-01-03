#pragma once

#include <Common/Common.h>
#include "PhongLightingComponent.h"

class PhongLightingApplication : public FirstPersonApplication
{
public:
	PhongLightingApplication(std::string name, int width, int height);
	virtual ~PhongLightingApplication();

	virtual void Initialize() override;
protected:
	PhongLightingComponent* mPhongLightingComponent;
};
