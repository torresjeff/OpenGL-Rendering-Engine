#include "GameException.h"

GameException::GameException(std::string data)
{
	this->data = data;
}

char const * GameException::what() const
{
	return data.c_str();
}
