#include <exception>
#include <string>

namespace myengine{

	class Exception : public std::exception
	{
	private:
		std::string m_message;

	public:
		Exception(std::string _message);
		~Exception() throw();
		const char* get();
	};
}
