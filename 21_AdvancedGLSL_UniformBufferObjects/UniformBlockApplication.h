#pragma once

#include <Common/Common.h>
#include "UniformBlockComponent.h"


class UniformBlockApplication : public FirstPersonApplication
{
public:
	UniformBlockApplication(std::string name, int width, int height);
	virtual ~UniformBlockApplication();

	virtual void Initialize() override;
private:
	UniformBlockComponent* mFaceCullingComponent;
};