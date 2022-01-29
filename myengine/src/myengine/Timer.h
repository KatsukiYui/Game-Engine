#include <chrono>
#include <thread>

#define timePoint std::chrono::steady_clock::time_point
#define duration std::chrono::duration<float>
#define clock std::chrono::steady_clock

class Timer
{
private:

	float m_targetFrameRate = 60.0f;
	float m_deltaTime = 0.0f;

	timePoint m_previousFrameEnd;

public:

	void WaitForFrameEnd(); //used to keep the frame rate constant

	float DeltaTime(); //getter for delta time
};