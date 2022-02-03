#include "Component.h"

namespace myengine
{
	/** Component for outputting an audio source. The camera has an audio listener.
	* @see AudioSource.h
	* @see Audio.h */
	class AudioListener : public Component
	{
	public:

		void update() override;
	};
}
