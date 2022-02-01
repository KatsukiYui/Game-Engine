#include "Asset.h"

namespace myengine
{
	class Texture : public Asset
	{
		void loadAsset(std::string _assetFolderPath, std::string _fileName) override;
	};
}
