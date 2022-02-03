#include "Component.h"

namespace myengine
{
	/** Class for playing an audio file. 
	* @see Audio.h */
	class AudioSource : public Component
	{
	public:

		void update() override;
	};
}
