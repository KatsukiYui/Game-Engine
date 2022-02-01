#include <map>
#include <string>
#include <fstream>
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
		
		template <typename T>
		shared<T> getAsset(std::string _fileName)
		{
			shared<T> rtn = std::make_shared<T>();

			try
			{
				//check if asset is in the map
				if (m_assets.count(_fileName))
				{
					// return asset
					rtn = std::dynamic_pointer_cast<T>(m_assets[_fileName]);
				}
				else
				{
					//if no then load it
					std::fstream fileStream;
					fileStream.open(m_assetFolderPath + _fileName);
					if (fileStream.is_open())
					{
						rtn->loadAsset(m_assetFolderPath, _fileName);
						//add it to the map
						m_assets.insert({ _fileName, rtn });
					}
					else
					{
						throw Exception("CANNOT FIND FILE: " + _fileName);
					}
					fileStream.close();
				}
			}
			catch (Exception e)
			{
				Debugger::printError(e.get());
			}	

			return rtn;
		}
	};
}