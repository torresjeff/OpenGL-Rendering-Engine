#include "LightMapsApplication.h"
#include <memory>

int main()
{
	std::unique_ptr<LightMapsApplication> application(new LightMapsApplication("Light Maps", 800, 600));

	try
	{
		application->Run();
	}
	catch (const GameException& exception)
	{
		std::cerr << exception.what() << "\n";
	}
}