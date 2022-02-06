#include <SDL.h>

#include "InputManager.h"
#include "Input.h"


namespace myengine
{
	InputManager::InputManager()
	{
		m_input = std::make_shared<Input>();
	}

	void InputManager::processFrameInput()
	{
		SDL_Event event = { 0 };

		m_input->refreshAtStartOfNewFrame();

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_MOUSEMOTION:
				m_input->m_relativeXPosition = event.motion.xrel;
				m_input->m_relativeYPosition = event.motion.yrel;
				break;
			case SDL_MOUSEWHEEL:
				m_input->m_scrollWheelDelta = event.wheel.y;
				break;
			case SDL_QUIT:
				m_input->m_SDLQuit = true;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					//Letters
				case SDLK_a:
					m_input->m_aDown = true;
					m_input->m_aHeld = true;
					break;
				case SDLK_b:
					m_input->m_bDown = true;
					m_input->m_bHeld = true;
					break;
				case SDLK_c:
					m_input->m_cDown = true;
					m_input->m_cHeld = true;
					break;
				case SDLK_d:
					m_input->m_dDown = true;
					m_input->m_dHeld = true;
					break;
				case SDLK_e:
					m_input->m_eDown = true;
					m_input->m_eHeld = true;
					break;
				case SDLK_f:
					m_input->m_fDown = true;
					m_input->m_fHeld = true;
					break;
				case SDLK_g:
					m_input->m_gDown = true;
					m_input->m_gHeld = true;
					break;
				case SDLK_h:
					m_input->m_hDown = true;
					m_input->m_hHeld = true;
					break;
				case SDLK_i:
					m_input->m_iDown = true;
					m_input->m_iHeld = true;
					break;
				case SDLK_j:
					m_input->m_jDown = true;
					m_input->m_jHeld = true;
					break;
				case SDLK_k:
					m_input->m_kDown = true;
					m_input->m_kHeld = true;
					break;
				case SDLK_l:
					m_input->m_lDown = true;
					m_input->m_lHeld = true;
					break;
				case SDLK_m:
					m_input->m_mDown = true;
					m_input->m_mHeld = true;
					break;
				case SDLK_n:
					m_input->m_nDown = true;
					m_input->m_nHeld = true;
					break;
				case SDLK_o:
					m_input->m_oDown = true;
					m_input->m_oHeld = true;
					break;
				case SDLK_p:
					m_input->m_pDown = true;
					m_input->m_pHeld = true;
					break;
				case SDLK_q:
					m_input->m_qDown = true;
					m_input->m_qHeld = true;
					break;
				case SDLK_r:
					m_input->m_rDown = true;
					m_input->m_rHeld = true;
					break;
				case SDLK_s:
					m_input->m_sDown = true;
					m_input->m_sHeld = true;
					break;
				case SDLK_t:
					m_input->m_tDown = true;
					m_input->m_tHeld = true;
					break;
				case SDLK_u:
					m_input->m_uDown = true;
					m_input->m_uHeld = true;
					break;
				case SDLK_v:
					m_input->m_vDown = true;
					m_input->m_vHeld = true;
					break;
				case SDLK_w:
					m_input->m_wDown = true;
					m_input->m_wHeld = true;
					break;
				case SDLK_x:
					m_input->m_xDown = true;
					m_input->m_xHeld = true;
					break;
				case SDLK_y:
					m_input->m_yDown = true;
					m_input->m_yHeld = true;
					break;
				case SDLK_z:
					m_input->m_zDown = true;
					m_input->m_zHeld = true;
					break;
					//Numbers
				case SDLK_0:
					m_input->m_0Down = true;
					m_input->m_0Held = true;
					break;
				case SDLK_1:
					m_input->m_1Down = true;
					m_input->m_1Held = true;
					break;
				case SDLK_2:
					m_input->m_2Down = true;
					m_input->m_2Held = true;
					break;
				case SDLK_3:
					m_input->m_3Down = true;
					m_input->m_3Held = true;
					break;
				case SDLK_4:
					m_input->m_4Down = true;
					m_input->m_4Held = true;
					break;
				case SDLK_5:
					m_input->m_5Down = true;
					m_input->m_5Held = true;
					break;
				case SDLK_6:
					m_input->m_6Down = true;
					m_input->m_6Held = true;
					break;
				case SDLK_7:
					m_input->m_7Down = true;
					m_input->m_7Held = true;
					break;
				case SDLK_8:
					m_input->m_8Down = true;
					m_input->m_8Held = true;
					break;
				case SDLK_9:
					m_input->m_9Down = true;
					m_input->m_9Held = true;
					break;
					//Special Keys
				case SDLK_ESCAPE:
					m_input->m_escapeDown = true;
					m_input->m_escapeHeld = true;
					break;
				case SDLK_SPACE:
					m_input->m_spaceDown = true;
					m_input->m_spaceHeld = true;
					break;
				case SDLK_LSHIFT:
					m_input->m_lShiftDown = true;
					m_input->m_lShiftHeld = true;
					break;
				case SDLK_LCTRL:
					m_input->m_lControlDown = true;
					m_input->m_lControlHeld = true;
					break;
				}
				break;
			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
					//Letters
				case SDLK_a:
					m_input->m_aReleased = true;
					m_input->m_aHeld = false;
					break;
				case SDLK_b:
					m_input->m_bReleased = true;
					m_input->m_bHeld = false;
					break;
				case SDLK_c:
					m_input->m_cReleased = true;
					m_input->m_cHeld = false;
					break;
				case SDLK_d:
					m_input->m_dReleased = true;
					m_input->m_dHeld = false;
					break;
				case SDLK_e:
					m_input->m_eReleased = true;
					m_input->m_eHeld = false;
					break;
				case SDLK_f:
					m_input->m_fReleased = true;
					m_input->m_fHeld = false;
					break;
				case SDLK_g:
					m_input->m_gReleased = true;
					m_input->m_gHeld = false;
					break;
				case SDLK_h:
					m_input->m_hReleased = true;
					m_input->m_hHeld = false;
					break;
				case SDLK_i:
					m_input->m_iReleased = true;
					m_input->m_iHeld = false;
					break;
				case SDLK_j:
					m_input->m_jReleased = true;
					m_input->m_jHeld = false;
					break;
				case SDLK_k:
					m_input->m_kReleased = true;
					m_input->m_kHeld = false;
					break;
				case SDLK_l:
					m_input->m_lReleased = true;
					m_input->m_lHeld = false;
					break;
				case SDLK_m:
					m_input->m_mReleased = true;
					m_input->m_mHeld = false;
					break;
				case SDLK_n:
					m_input->m_nReleased = true;
					m_input->m_nHeld = false;
					break;
				case SDLK_o:
					m_input->m_oReleased = true;
					m_input->m_oHeld = false;
					break;
				case SDLK_p:
					m_input->m_pReleased = true;
					m_input->m_pHeld = false;
					break;
				case SDLK_q:
					m_input->m_qReleased = true;
					m_input->m_qHeld = false;
					break;
				case SDLK_r:
					m_input->m_rReleased = true;
					m_input->m_rHeld = false;
					break;
				case SDLK_s:
					m_input->m_sReleased = true;
					m_input->m_sHeld = false;
					break;
				case SDLK_t:
					m_input->m_tReleased = true;
					m_input->m_tHeld = false;
					break;
				case SDLK_u:
					m_input->m_uReleased = true;
					m_input->m_uHeld = false;
					break;
				case SDLK_v:
					m_input->m_vReleased = true;
					m_input->m_vHeld = false;
					break;
				case SDLK_w:
					m_input->m_wReleased = true;
					m_input->m_wHeld = false;
					break;
				case SDLK_x:
					m_input->m_xReleased = true;
					m_input->m_xHeld = false;
					break;
				case SDLK_y:
					m_input->m_yReleased = true;
					m_input->m_yHeld = false;
					break;
				case SDLK_z:
					m_input->m_zReleased = true;
					m_input->m_zHeld = false;
					break;
					//Numbers
				case SDLK_0:
					m_input->m_0Released = true;
					m_input->m_0Held = false;
					break;
				case SDLK_1:
					m_input->m_1Released = true;
					m_input->m_1Held = false;
					break;
				case SDLK_2:
					m_input->m_2Released = true;
					m_input->m_2Held = false;
					break;
				case SDLK_3:
					m_input->m_3Released = true;
					m_input->m_3Held = false;
					break;
				case SDLK_4:
					m_input->m_4Released = true;
					m_input->m_4Held = false;
					break;
				case SDLK_5:
					m_input->m_5Released = true;
					m_input->m_5Held = false;
					break;
				case SDLK_6:
					m_input->m_6Released = true;
					m_input->m_6Held = false;
					break;
				case SDLK_7:
					m_input->m_7Released = true;
					m_input->m_7Held = false;
					break;
				case SDLK_8:
					m_input->m_8Released = true;
					m_input->m_8Held = false;
					break;
				case SDLK_9:
					m_input->m_9Released = true;
					m_input->m_9Held = false;
					break;
					//Special Keys
				case SDLK_ESCAPE:
					m_input->m_escapeReleased = true;
					m_input->m_escapeHeld = false;
					break;
				case SDLK_SPACE:
					m_input->m_spaceReleased = true;
					m_input->m_spaceHeld = false;
					break;
				case SDLK_LSHIFT:
					m_input->m_lShiftReleased = true;
					m_input->m_lShiftHeld = false;
					break;
				case SDLK_LCTRL:
					m_input->m_lControlReleased = true;
					m_input->m_lControlHeld = false;
					break;
				}
				break;
			}
		}
	}

	shared<Input> InputManager::getInput() 
	{ 
		return m_input; 
	}
}
