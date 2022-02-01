#ifndef H_ASSET
#define H_ASSET

#include <string>

namespace myengine
{
	class Asset
	{
	protected:
		std::string m_fileName;
	public:
		//load fn
		virtual void loadAsset(std::string _assetFolderPath, std::string _fileName);

	};
}

#endif