#pragma once

#include <glm/glm.hpp>
#include "InputManager.h"

namespace myengine
{

	enum Keys
	{
		A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		k0, k1, k2, k3, k4, k5, k6, k7, k8, k9,
		SPACE, LSHIFT, LCNTRL, ESCAPE
	};

	enum Mouse
	{
		Left, Right
	};

	/**	The Inputs class is used to store the current frames input data. This can then be accessed from Component classes and other places in the program to perfrom user driven actions.  	*/
	class Input
	{
		friend InputManager;

	private:
		// Events
		bool m_SDLQuit;

		// Mouse Input
		float m_relativeXPosition;
		float m_relativeYPosition;
		float m_scrollWheelDelta;

		bool m_leftClickDown, m_leftClickHeld, m_leftClickReleased;
		bool m_rightClickDown, m_rightClickHeld, m_rightClickReleased;

		// Keyboard Input
		bool m_aDown, m_aHeld, m_aReleased;
		bool m_bDown, m_bHeld, m_bReleased;
		bool m_cDown, m_cHeld, m_cReleased;
		bool m_dDown, m_dHeld, m_dReleased;
		bool m_eDown, m_eHeld, m_eReleased;
		bool m_fDown, m_fHeld, m_fReleased;
		bool m_gDown, m_gHeld, m_gReleased;
		bool m_hDown, m_hHeld, m_hReleased;
		bool m_iDown, m_iHeld, m_iReleased;
		bool m_jDown, m_jHeld, m_jReleased;
		bool m_kDown, m_kHeld, m_kReleased;
		bool m_lDown, m_lHeld, m_lReleased;
		bool m_mDown, m_mHeld, m_mReleased;
		bool m_nDown, m_nHeld, m_nReleased;
		bool m_oDown, m_oHeld, m_oReleased;
		bool m_pDown, m_pHeld, m_pReleased;
		bool m_qDown, m_qHeld, m_qReleased;
		bool m_rDown, m_rHeld, m_rReleased;
		bool m_sDown, m_sHeld, m_sReleased;
		bool m_tDown, m_tHeld, m_tReleased;
		bool m_uDown, m_uHeld, m_uReleased;
		bool m_vDown, m_vHeld, m_vReleased;
		bool m_wDown, m_wHeld, m_wReleased;
		bool m_xDown, m_xHeld, m_xReleased;
		bool m_yDown, m_yHeld, m_yReleased;
		bool m_zDown, m_zHeld, m_zReleased;

		bool m_0Down, m_0Held, m_0Released;
		bool m_1Down, m_1Held, m_1Released;
		bool m_2Down, m_2Held, m_2Released;
		bool m_3Down, m_3Held, m_3Released;
		bool m_4Down, m_4Held, m_4Released;
		bool m_5Down, m_5Held, m_5Released;
		bool m_6Down, m_6Held, m_6Released;
		bool m_7Down, m_7Held, m_7Released;
		bool m_8Down, m_8Held, m_8Released;
		bool m_9Down, m_9Held, m_9Released;

		bool m_escapeDown, m_escapeHeld, m_escapeReleased;
		bool m_spaceDown, m_spaceHeld, m_spaceReleased;
		bool m_lShiftDown, m_lShiftHeld, m_lShiftReleased;
		bool m_lControlDown, m_lControlHeld, m_lControlReleased;

		void refreshAtStartOfNewFrame();

	public:

		bool isKeyDown(Keys _key);
		bool isKeyHeld(Keys _key);
		bool isKeyReleased(Keys _key);

		bool isMouseDown(Mouse _mouse);
		bool isMouseHeld(Mouse _mouse);
		bool isMouseReleased(Mouse _mouse);

		glm::vec2 getMousePosition();
		float getMouseScrollDelta();

		bool quit();
	};
}