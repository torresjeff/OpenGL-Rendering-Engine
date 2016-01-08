#include "BlendingApplication.h"
#include <memory>

int main()
{
	std::unique_ptr<BlendingApplication> application(new BlendingApplication("Blending", 800, 600));

	try
	{
		application->Run();
	}
	catch (const GameException& exception)
	{
		std::cerr << exception.what() << "\n";
	}
}