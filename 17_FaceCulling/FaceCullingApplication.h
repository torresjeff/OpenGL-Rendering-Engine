#pragma once

#include <Common/Common.h>
#include "FaceCullingComponent.h"


class FaceCullingApplication : public FirstPersonApplication
{
public:
	FaceCullingApplication(std::string name, int width, int height);
	virtual ~FaceCullingApplication();

	virtual void Initialize() override;
private:
	FaceCullingComponent* mFaceCullingComponent;
};