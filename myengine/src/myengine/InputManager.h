#ifndef H_INPUT_MAN_
#define H_INPUT_MAN_

#include "MemoryDefines.h"

namespace myengine
{
	class Core;
	class Input;

	/**	The InputManager is used to update the current frames input from SDL2's input events.  	*/
	class InputManager
	{
	private:
		shared<Input> m_input;
		void processFrameInput();

	public:
		InputManager();
		shared<Input> getInput();
	};

}

#endif