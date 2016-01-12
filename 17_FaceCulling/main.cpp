#include "FaceCullingApplication.h"
#include <memory>

int main()
{
	std::unique_ptr<FaceCullingApplication> application(new FaceCullingApplication("Depth Testing", 800, 600));

	try
	{
		application->Run();
	}
	catch (const GameException& exception)
	{
		std::cerr << exception.what() << "\n";
	}
}