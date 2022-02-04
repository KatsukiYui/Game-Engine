#include "Component.h"
#include "MemoryDefines.h"
#include <al.h>
#include <alc.h>

namespace myengine
{
	class Audio;

	/** Class for playing an audio file. 
	* @see Audio.h */
	class AudioSource : public Component
	{
	private:
		ALuint m_sourceID;
		bool m_loop = false;
		shared<Audio> m_audio;

	public:
		~AudioSource();
		void postInitialize(shared<Component> _self, shared<Entity> _entity) override;
		void update() override;
		void play();
		void setLooping(bool _loop);
		void setAudio(shared<Audio> _audio);

	};
}