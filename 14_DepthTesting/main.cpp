#include "DepthTestingApplication.h"
#include <memory>

int main()
{
	std::unique_ptr<DepthTestingApplication> application(new DepthTestingApplication("Depth Testing", 800, 600));

	try
	{
		application->Run();
	}
	catch (const GameException& exception)
	{
		std::cerr << exception.what() << "\n";
	}
}