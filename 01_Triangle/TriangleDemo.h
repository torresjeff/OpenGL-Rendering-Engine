#pragma once

#include <Common/Common.h>

class TriangleDemo : public Application
{
public:
	TriangleDemo(std::string name, int width, int height);

	virtual void Run() override;
};

