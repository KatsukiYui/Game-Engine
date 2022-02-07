#include "Input.h"

namespace myengine
{
	void Input::refreshAtStartOfNewFrame()
	{
		// - [Events] -
		m_SDLQuit = false;

		// - [Mouse Input] -
		m_relativeXPosition = 0;
		m_relativeYPosition = 0;
		m_scrollWheelDelta = 0;

		m_leftClickDown = false, m_leftClickReleased = false;
		m_rightClickDown = false, m_rightClickReleased = false;

		// - [Keyboard Input] - 
		m_aDown = false, m_aReleased = false;
		m_bDown = false, m_bReleased = false;
		m_cDown = false, m_cReleased = false;
		m_dDown = false, m_dReleased = false;
		m_eDown = false, m_eReleased = false;
		m_fDown = false, m_fReleased = false;
		m_gDown = false, m_gReleased = false;
		m_hDown = false, m_hReleased = false;
		m_iDown = false, m_iReleased = false;
		m_jDown = false, m_jReleased = false;
		m_kDown = false, m_kReleased = false;
		m_lDown = false, m_lReleased = false;
		m_mDown = false, m_mReleased = false;
		m_nDown = false, m_nReleased = false;
		m_oDown = false, m_oReleased = false;
		m_pDown = false, m_pReleased = false;
		m_qDown = false, m_qReleased = false;
		m_rDown = false, m_rReleased = false;
		m_sDown = false, m_sReleased = false;
		m_tDown = false, m_tReleased = false;
		m_uDown = false, m_uReleased = false;
		m_vDown = false, m_vReleased = false;
		m_wDown = false, m_wReleased = false;
		m_xDown = false, m_xReleased = false;
		m_yDown = false, m_yReleased = false;
		m_zDown = false, m_zReleased = false;

		m_0Down = false, m_0Released = false;
		m_1Down = false, m_1Released = false;
		m_2Down = false, m_2Released = false;
		m_3Down = false, m_3Released = false;
		m_4Down = false, m_4Released = false;
		m_5Down = false, m_5Released = false;
		m_6Down = false, m_6Released = false;
		m_7Down = false, m_7Released = false;
		m_8Down = false, m_8Released = false;
		m_9Down = false, m_9Released = false;

		m_escapeDown = false, m_escapeReleased = false;
		m_spaceDown = false, m_spaceReleased = false;
		m_lShiftDown = false, m_lShiftReleased = false;
		m_lControlDown = false, m_lControlReleased = false;
	}

	bool Input::isMouseDown(Mouse _mouse)
	{
		bool result = false;
		switch (_mouse)
		{
			case Left:
			{
				result = m_leftClickDown;
			} break;
			case Right:
			{
				result = m_rightClickDown;
			} break;
		}

		return result;
	}

	bool Input::isMouseHeld(Mouse _mouse)
	{
		bool result = false;
		switch (_mouse)
		{
			case Left:
			{
				result = m_leftClickHeld;
			} break;
			case Right:
			{
				result = m_rightClickHeld;
			} break;
		}

		return result;
	}

	bool Input::isMouseReleased(Mouse _mouse)
	{
		bool result = false;
		switch (_mouse)
		{
			case Left:
			{
				result = m_leftClickReleased;
			} break;
			case Right:
			{
				result = m_rightClickReleased;
			} break;
		}

		return result;
	}

	bool Input::isKeyDown(Keys _key)
	{
		bool result = false;
		switch (_key)
		{
			// Letters
		case A:
		{
			result = m_aDown;
		} break;
		case B:
		{
			result = m_bDown;
		} break;
		case C:
		{
			result = m_cDown;
		} break;
		case D:
		{
			result = m_dDown;
		} break;
		case E:
		{
			result = m_eDown;
		} break;
		case F:
		{
			result = m_fDown;
		} break;
		case G:
		{
			result = m_gDown;
		} break;
		case H:
		{
			result = m_hDown;
		} break;
		case I:
		{
			result = m_iDown;
		} break;
		case J:
		{
			result = m_jDown;
		} break;
		case K:
		{
			result = m_kDown;
		} break;
		case L:
		{
			result = m_lDown;
		} break;
		case M:
		{
			result = m_mDown;
		} break;
		case N:
		{
			result = m_nDown;
		} break;
		case O:
		{
			result = m_oDown;
		} break;
		case P:
		{
			result = m_pDown;
		} break;
		case Q:
		{
			result = m_qDown;
		} break;
		case R:
		{
			result = m_rDown;
		} break;
		case S:
		{
			result = m_sDown;
		} break;
		case T:
		{
			result = m_tDown;
		} break;
		case U:
		{
			result = m_uDown;
		} break;
		case V:
		{
			result = m_vDown;
		} break;
		case W:
		{
			result = m_wDown;
		} break;
		case X:
		{
			result = m_xDown;
		} break;
		case Y:
		{
			result = m_yDown;
		} break;
		case Z:
		{
			result = m_zDown;
		} break;
		// Numbers
		case k0:
		{
			result = m_0Down;
		} break;
		case k1:
		{
			result = m_1Down;
		} break;
		case k2:
		{
			result = m_2Down;
		} break;
		case k3:
		{
			result = m_3Down;
		} break;
		case k4:
		{
			result = m_4Down;
		} break;
		case k5:
		{
			result = m_5Down;
		} break;
		case k6:
		{
			result = m_6Down;
		} break;
		case k7:
		{
			result = m_7Down;
		} break;
		case k8:
		{
			result = m_8Down;
		} break;
		case k9:
		{
			result = m_9Down;
		} break;
		// Special Keys
		case ESCAPE:
		{
			result = m_escapeDown;
		} break;
		case SPACE:
		{
			result = m_spaceDown;
		} break;
		case LSHIFT:
		{
			result = m_lShiftDown;
		} break;
		case LCNTRL:
		{
			result = m_lControlDown;
		} break;
		}

		return result;
	}

	bool Input::isKeyHeld(Keys _key)
	{
		bool result = false;
		switch (_key)
		{
			// Letters
		case A:
		{
			result = m_aHeld;
		} break;
		case B:
		{
			result = m_bHeld;
		} break;
		case C:
		{
			result = m_cHeld;
		} break;
		case D:
		{
			result = m_dHeld;
		} break;
		case E:
		{
			result = m_eHeld;
		} break;
		case F:
		{
			result = m_fDown;
		} break;
		case G:
		{
			result = m_gDown;
		} break;
		case H:
		{
			result = m_hHeld;
		} break;
		case I:
		{
			result = m_iHeld;
		} break;
		case J:
		{
			result = m_jHeld;
		} break;
		case K:
		{
			result = m_kHeld;
		} break;
		case L:
		{
			result = m_lHeld;
		} break;
		case M:
		{
			result = m_mHeld;
		} break;
		case N:
		{
			result = m_nHeld;
		} break;
		case O:
		{
			result = m_oHeld;
		} break;
		case P:
		{
			result = m_pHeld;
		} break;
		case Q:
		{
			result = m_qHeld;
		} break;
		case R:
		{
			result = m_rHeld;
		} break;
		case S:
		{
			result = m_sHeld;
		} break;
		case T:
		{
			result = m_tHeld;
		} break;
		case U:
		{
			result = m_uHeld;
		} break;
		case V:
		{
			result = m_vHeld;
		} break;
		case W:
		{
			result = m_wHeld;
		} break;
		case X:
		{
			result = m_xHeld;
		} break;
		case Y:
		{
			result = m_yHeld;
		} break;
		case Z:
		{
			result = m_zHeld;
		} break;
		// Numbers
		case k0:
		{
			result = m_0Held;
		} break;
		case k1:
		{
			result = m_1Held;
		} break;
		case k2:
		{
			result = m_2Held;
		} break;
		case k3:
		{
			result = m_3Held;
		} break;
		case k4:
		{
			result = m_4Held;
		} break;
		case k5:
		{
			result = m_5Held;
		} break;
		case k6:
		{
			result = m_6Held;
		} break;
		case k7:
		{
			result = m_7Held;
		} break;
		case k8:
		{
			result = m_8Held;
		} break;
		case k9:
		{
			result = m_9Held;
		} break;
		// Special Keys
		case ESCAPE:
		{
			result = m_escapeHeld;
		} break;
		case SPACE:
		{
			result = m_spaceHeld;
		} break;
		case LSHIFT:
		{
			result = m_lShiftHeld;
		} break;
		case LCNTRL:
		{
			result = m_lControlHeld;
		} break;
		}

		return result;
	}

	bool Input::isKeyReleased(Keys _key)
	{
		bool result = false;
		switch (_key)
		{
			//Letters
		case A:
		{
			result = m_aReleased;
		} break;
		case B:
		{
			result = m_bReleased;
		} break;
		case C:
		{
			result = m_cReleased;
		} break;
		case D:
		{
			result = m_dReleased;
		} break;
		case E:
		{
			result = m_eReleased;
		} break;
		case F:
		{
			result = m_fReleased;
		} break;
		case G:
		{
			result = m_gReleased;
		} break;
		case H:
		{
			result = m_hReleased;
		} break;
		case I:
		{
			result = m_iReleased;
		} break;
		case J:
		{
			result = m_jReleased;
		} break;
		case K:
		{
			result = m_kReleased;
		} break;
		case L:
		{
			result = m_lReleased;
		} break;
		case M:
		{
			result = m_mReleased;
		} break;
		case N:
		{
			result = m_nReleased;
		} break;
		case O:
		{
			result = m_oReleased;
		} break;
		case P:
		{
			result = m_pReleased;
		} break;
		case Q:
		{
			result = m_qReleased;
		} break;
		case R:
		{
			result = m_rReleased;
		} break;
		case S:
		{
			result = m_sReleased;
		} break;
		case T:
		{
			result = m_tReleased;
		} break;
		case U:
		{
			result = m_uReleased;
		} break;
		case V:
		{
			result = m_vReleased;
		} break;
		case W:
		{
			result = m_wReleased;
		} break;
		case X:
		{
			result = m_xReleased;
		} break;
		case Y:
		{
			result = m_yReleased;
		} break;
		case Z:
		{
			result = m_zReleased;
		} break;
		// Numbers
		case k0:
		{
			result = m_0Released;
		} break;
		case k1:
		{
			result = m_1Released;
		} break;
		case k2:
		{
			result = m_2Released;
		} break;
		case k3:
		{
			result = m_3Released;
		} break;
		case k4:
		{
			result = m_4Released;
		} break;
		case k5:
		{
			result = m_5Released;
		} break;
		case k6:
		{
			result = m_6Released;
		} break;
		case k7:
		{
			result = m_7Released;
		} break;
		case k8:
		{
			result = m_8Released;
		} break;
		case k9:
		{
			result = m_9Released;
		} break;
		// Special Keys
		case ESCAPE:
		{
			result = m_escapeReleased;
		} break;
		case SPACE:
		{
			result = m_spaceReleased;
		} break;
		case LSHIFT:
		{
			result = m_lShiftReleased;
		} break;
		case LCNTRL:
		{
			result = m_lControlReleased;
		} break;
		}

		return result;
	}

	glm::vec2 Input::getMousePosition() 
	{ 
		return glm::vec2(m_relativeXPosition, m_relativeYPosition); 
	}

	float Input::getMouseScrollDelta() 
	{ 
		return m_scrollWheelDelta; 
	}

	bool Input::quit() 
	{ 
		return m_SDLQuit; 
	}
}