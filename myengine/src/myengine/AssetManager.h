#include <map>
#include <string>
#include "MemoryDefines.h"

namespace myengine
{
	class Asset;
	class Core;
	class AssetManager
	{
	private:
		std::map <std::string, shared<Asset>> m_assets;
		std::string m_assetFolderPath;
		weak<AssetManager> m_self;
		weak<Core> m_core;

	public:
		bool findAssetFolder();
		void initialize(shared<AssetManager> _self, shared<Core> _core);
		shared<Core> getCore();
	};
}