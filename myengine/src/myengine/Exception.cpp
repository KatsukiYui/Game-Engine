#include "Exception.h"

myengine::Exception::Exception(std::string _message)
{
	m_message = _message;
}

myengine::Exception::~Exception()
{

}

const char* myengine::Exception::get()
{
	return m_message.c_str();
}
