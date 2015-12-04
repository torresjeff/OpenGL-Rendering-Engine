#include "TriangleApplication.h"
#include <memory>

int main()
{
	std::unique_ptr<TriangleApplication> triangleDemo(new TriangleApplication("Triangle", 800, 600));

	try
	{
		triangleDemo->Run();
	}
	catch (const GameException& exception)
	{
		cout << exception.what() << "\n";
	}

	return 0;
}