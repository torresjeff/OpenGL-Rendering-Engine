#include "MultipleLightsApplication.h"
#include <memory>

int main()
{
	std::unique_ptr<MultipleLightsApplication> application(new MultipleLightsApplication("Multiple Lights", 800, 600));

	try
	{
		application->Run();
	}
	catch (const GameException& exception)
	{
		std::cerr << exception.what() << "\n";
	}
}