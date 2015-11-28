#pragma once

#include <exception>
#include <string>

class GameException : public std::exception
{
public:
	GameException(std::string data);
	virtual char const* what() const override;

private:
	std::string data;
};
