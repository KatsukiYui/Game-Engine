#include <exception>
#include <string>

namespace myengine{

	class Exception : public std::exception
	{
	public:
		Exception(std::string _message);
		~Exception() throw();
		const char* get();
	private:
		std::string m_message;
	};
}
