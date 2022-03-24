#include <exception>
#include <string>

namespace myengine
{
	/** Stores a message for the exception to be printed. */
	class Exception : public std::exception
	{
	private:
		std::string m_message;

	public:
		Exception(std::string _message);
		~Exception() throw();
		const char* get(); /**< Getter - Returns Exception::m_message */
	};
}
