#include "AudioListener.h"
#include "Transform.h"
#include <al.h>
#include <alc.h>

namespace myengine
{
	void AudioListener::update()
	{
		glm::vec3 position = getTransform()->getPosition();
		alListener3f(AL_POSITION, position.x, position.y, position.z);
	}
}
