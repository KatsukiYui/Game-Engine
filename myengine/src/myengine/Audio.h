#include "Asset.h"
#include <al.h>
#include <alc.h>

namespace myengine
{
	/** Represents a .ogg file.
	* @see Asset.h	*/
	class Audio : public Asset
	{
	protected:
		ALuint m_audioID;
		ALenum m_format;
	public:
		/** Loads the .ogg file from the asset folder.
		* Overrides Asset::loadAsset() in parent class.
		* @see Asset.h	*/
		void loadAsset(std::string _assetFolderPath, std::string _fileName) override;
		ALuint getAudioID();
		ALenum getFormat();
		~Audio();
	};
}
