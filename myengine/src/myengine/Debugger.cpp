#include "Debugger.h"

void Debugger::printLog(std::string message)
{
	std::cout << GREEN << "Log: " << RESET << message << std::endl;
}

void Debugger::printWarning(std::string message)
{
	std::cout << CYAN << "Log: " << RESET << message << std::endl;
}

void Debugger::printError(std::string message)
{
	std::cout << RED << "Log: " << RESET << message << std::endl;
}
