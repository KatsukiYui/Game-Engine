#include "stb/stb_vorbis.h"

#include "Audio.h"
#include "Exception.h"
#include "MemoryDefines.h"
#include <vector>

namespace myengine
{
	void Audio::loadAsset(std::string _assetFolderPath, std::string _fileName)
	{
		m_fileName = _fileName;
		std::string path = _assetFolderPath + _fileName;

		short* decodedAudio = NULL;
		int channels = 0, sampleRate = 0;

		int sampleCount = stb_vorbis_decode_filename(path.c_str(), &channels, &sampleRate, &decodedAudio);
		
		if (sampleCount == -1)
		{
			throw Exception("Failed to load audio file: " + _fileName);
		}
		else
		{
			sampleCount = sampleCount - sampleCount % 4;

			m_format = ((channels == 1) ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16);
			ALsizei frequancy = sampleRate;
			std::vector<char> data;
			
			data.resize(sampleCount * 2);
			memcpy(&(data.at(0)), decodedAudio, data.size());
			
			alGenBuffers(1, &m_audioID);

			alBufferData(m_audioID, m_format, &data.at(0), (ALsizei)(data.size()), frequancy);

		}

		free(decodedAudio);
	}

	ALuint Audio::getAudioID()
	{
		return m_audioID;
	}

	ALenum Audio::getFormat()
	{
		return m_format;
	}

	Audio::~Audio()
	{
		alDeleteBuffers(1, &m_audioID);
	}
}