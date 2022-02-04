#include "InputManager.h"

namespace myengine
{
	Keys InputManager::Update()
	{

		switch (*Key)
		{
			case SDL_SCANCODE_W :
				return Up;
				break;
			case SDL_SCANCODE_S :
				return Down;
				break;
		}








		if (Key[SDL_SCANCODE_W])//scans if the W key was pressed etc and returns the corresponding enum key ID/name 
		{
			return Up;
		}
		if (Key[SDL_SCANCODE_S])
		{
			return Down;
		}
		if (Key[SDL_SCANCODE_D])
		{
			return Right;

		}
		if (Key[SDL_SCANCODE_A])
		{
			return Left;
		}
		if (Key[SDL_SCANCODE_LSHIFT] || Key[SDL_SCANCODE_RSHIFT])
		{
			return Shift;
		}

		return None;//return none if no key or none of the above keys were pressed
	}
}
