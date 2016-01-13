#pragma once

#include <Common/Common.h>
#include "FrambuffersComponent.h"


class FramebuffersApplication : public FirstPersonApplication
{
public:
	FramebuffersApplication(std::string name, int width, int height);
	virtual ~FramebuffersApplication();

	virtual void Initialize() override;
private:
	FrambuffersComponent* mLightMapsComponent;
};