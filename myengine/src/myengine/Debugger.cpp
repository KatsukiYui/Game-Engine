#include "Debugger.h"

namespace myengine
{
	void Debugger::printLog(std::string _message)
	{
		std::cout << GREEN << "Log: " << RESET << _message << std::endl;
	}

	void Debugger::printWarning(std::string _message)
	{
		std::cout << CYAN << "Log: " << RESET << _message << std::endl;
	}

	void Debugger::printError(std::string _message)
	{
		std::cout << RED << "Log: " << RESET << _message << std::endl;
	}
}
