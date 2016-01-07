#pragma once

#include <Common/Common.h>
#include "DepthTestingComponent.h"


class DepthTestingApplication : public FirstPersonApplication
{
public:
	DepthTestingApplication(std::string name, int width, int height);
	virtual ~DepthTestingApplication();

	virtual void Initialize() override;
private:
	DepthTestingComponent* mLightMapsComponent;
};