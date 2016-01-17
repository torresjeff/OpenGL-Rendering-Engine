#include "CubemapApplication.h"
#include <memory>

int main()
{
	std::unique_ptr<CubemapApplication> application(new CubemapApplication("Cubemap", 800, 600));

	try
	{
		application->Run();
	}
	catch (const GameException& exception)
	{
		std::cerr << exception.what() << "\n";
	}
}