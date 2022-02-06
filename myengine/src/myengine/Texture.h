#include "Asset.h"

namespace myengine
{	
	/** Represents a BMP texture.
	* @see Asset.h	*/
	class Texture : public Asset
	{
	private:
		unsigned int m_textureID;
	public:
		/** Loads the BMP from the asset folder.
		* Overrides Asset::loadAsset() in parent class.
		* @see Asset.h	*/
		void loadAsset(std::string _assetFolderPath, std::string _fileName) override; 

		unsigned int getTextureID();
	};
}
