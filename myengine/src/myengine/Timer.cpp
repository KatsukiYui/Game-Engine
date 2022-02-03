#include "Timer.h"

namespace myengine
{
	void Timer::WaitForFrameEnd()
	{
		duration timeElapsed = clock::now() - m_previousFrameEnd;
		float waitDuration = ((1 / m_targetFrameRate) - timeElapsed.count()) * 1000.0f;

		if (waitDuration > 0)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds((int)waitDuration));
		}

		timePoint sleepEnd = clock::now();

		timeElapsed = sleepEnd - m_previousFrameEnd;
		m_previousFrameEnd = sleepEnd;
		m_deltaTime = timeElapsed.count();
	}

	float Timer::DeltaTime()
	{
		return m_deltaTime;
	}
}
