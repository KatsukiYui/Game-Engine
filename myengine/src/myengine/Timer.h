#include <chrono>
#include <thread>

namespace myengine
{

#define timePoint std::chrono::steady_clock::time_point
#define duration std::chrono::duration<float>
#define clock std::chrono::steady_clock

	class Timer
	{
	protected:
		float m_targetFrameRate = 60.0f;
		float m_deltaTime = 0.0f;

		/** Used to calculate delta time. */
		timePoint m_previousFrameEnd;

	public:
		/** Used to keep the frame rate constant. */
		void WaitForFrameEnd();

		float DeltaTime(); /**< Getter - Returns Timer::m_deltatime */
	};
}