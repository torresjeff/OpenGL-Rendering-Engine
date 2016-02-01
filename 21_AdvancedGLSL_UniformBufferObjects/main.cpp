#include "UniformBlockApplication.h"
#include <memory>

int main()
{
	std::unique_ptr<UniformBlockApplication> application(new UniformBlockApplication("Cubemap", 800, 600));

	try
	{
		application->Run();
	}
	catch (const GameException& exception)
	{
		std::cerr << exception.what() << "\n";
	}
}