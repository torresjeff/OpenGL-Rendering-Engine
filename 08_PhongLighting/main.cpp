#include "PhongLightingApplication.h"
#include <memory>

int main()
{
	std::unique_ptr<PhongLightingApplication> application(new PhongLightingApplication("Phong Lighting Model", 800, 600));
	
	try
	{
		application->Run();
	}
	catch (const GameException& exception)
	{
		std::cerr << exception.what() << "\n";
	}
}