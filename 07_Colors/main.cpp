#include "ColorsApplication.h"
#include <memory>


int main()
{
	std::unique_ptr<ColorsApplication> application(new ColorsApplication("Colors", 800, 600));
	
	try
	{
		application->Run();
	}
	catch (const GameException& exception)
	{
		std::cerr << exception.what() << "\n";
	}
}