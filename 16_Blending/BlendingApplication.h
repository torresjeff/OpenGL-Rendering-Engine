#pragma once

#include <Common/Common.h>
#include "BlendingComponent.h"


class BlendingApplication : public FirstPersonApplication
{
public:
	BlendingApplication(std::string name, int width, int height);
	virtual ~BlendingApplication();

	virtual void Initialize() override;
private:
	BlendingComponent* mLightMapsComponent;
};