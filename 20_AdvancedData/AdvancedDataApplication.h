#pragma once

#include <Common/Common.h>
#include "AdvancedDataComponent.h"


class AdvancedDataApplication : public FirstPersonApplication
{
public:
	AdvancedDataApplication(std::string name, int width, int height);
	virtual ~AdvancedDataApplication();

	virtual void Initialize() override;
private:
	AdvancedDataComponent* mFaceCullingComponent;
};