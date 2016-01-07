#include "StencilTestingApplication.h"
#include <memory>

int main()
{
	std::unique_ptr<StencilTestingApplication> application(new StencilTestingApplication("Stencil Testing", 800, 600));

	try
	{
		application->Run();
	}
	catch (const GameException& exception)
	{
		std::cerr << exception.what() << "\n";
	}
}