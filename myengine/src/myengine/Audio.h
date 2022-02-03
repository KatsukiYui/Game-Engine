#include "Asset.h"

namespace myengine
{
	/** Represents a .ogg file.
	* @see Asset.h	*/
	class Audio : public Asset
	{
	public:
		/** Loads the .ogg file from the asset folder.
		* Overrides Asset::loadAsset() in parent class.
		* @see Asset.h	*/
		void loadAsset(std::string _assetFolderPath, std::string _fileName) override;
	};
}
