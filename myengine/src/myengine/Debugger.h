#include <string>
#include <iostream>

namespace myengine
{

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /**< Black */
#define RED     "\033[31m"      /**< Red */
#define GREEN   "\033[32m"      /**< Green */
#define YELLOW  "\033[33m"      /**< Yellow */
#define BLUE    "\033[34m"      /**< Blue */
#define MAGENTA "\033[35m"      /**< Magenta */
#define CYAN    "\033[36m"      /**< Cyan */
#define WHITE   "\033[37m"      /**< White */


	/** Used to output messages onto the console.
	* The functions all do the same thing but with different colors.
	* @see Exception.h */
	class Debugger
	{
	public:

		static void printLog(std::string _message);
		static void printWarning(std::string _message);
		static void printError(std::string _message);
	};
}