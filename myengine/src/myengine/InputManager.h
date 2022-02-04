#ifndef H_KEYBOARD_
#define H_KEYBOARD_

#include <SDL.h>

namespace myengine
{

	enum Keys { Up, Down, Right, Left, Shift, None };//used to return the key that was pressed

	class InputManager
	{
	protected:
		const Uint8* Key = SDL_GetKeyboardState(NULL);//used to scan keycodes


	public:

		//returns a key ID/name if a key was pressed. Else returns none.
		Keys Update();

	};
}

#endif // !H_KEYBOARD_