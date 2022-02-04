#include "AudioSource.h"
#include "Exception.h"
#include "Debugger.h"
#include "Transform.h"
#include "Audio.h"

namespace myengine
{
	void AudioSource::postInitialize(shared<Component> _self, shared<Entity> _entity)
	{
		alGenSources(1, &m_sourceID);

		if (alGetError() != AL_NO_ERROR)
		{
			throw Exception("Failed to generate 'Audio Source' ID");
		}
	}

	void AudioSource::update()
	{
		glm::vec3 position = getTransform()->getPosition();
		alSource3f(m_sourceID, AL_POSITION, position.x, position.y, position.z);
	}

	void AudioSource::play()
	{
		if (m_audio)
		{
			if (m_audio->getFormat() == AL_FORMAT_STEREO16)
			{
				Debugger::printWarning("Audio file '" + m_audio->getFileName() + "' is of type 'AL_FORMAT_STEREO16' this will not work with spatial sound.");
			}

			alSourceStop(m_sourceID);
			alSourcei(m_sourceID, AL_BUFFER, m_audio->getAudioID());

			alSourcePlay(m_sourceID);
		}
	}

	void AudioSource::setLooping(bool _loop)
	{
		m_loop = _loop;
	}

	void AudioSource::setAudio(shared<Audio> _audio)
	{
		m_audio = _audio;
	}

	AudioSource::~AudioSource()
	{
		alDeleteSources(1, &m_sourceID);
	}
}
