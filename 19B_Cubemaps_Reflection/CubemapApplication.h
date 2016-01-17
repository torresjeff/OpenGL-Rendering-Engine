#pragma once

#include <Common/Common.h>
#include "CubemapComponent.h"


class CubemapApplication : public FirstPersonApplication
{
public:
	CubemapApplication(std::string name, int width, int height);
	virtual ~CubemapApplication();

	virtual void Initialize() override;
private:
	CubemapComponent* mFaceCullingComponent;
};