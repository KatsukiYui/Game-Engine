#include <Windows.h>
#include<fstream>
#include <filesystem>

#include "AssetManager.h"
#include "Exception.h"

namespace myengine
{
	bool AssetManager::findAssetFolder()
	{
		char executablePathAsArray[_MAX_PATH];
		GetModuleFileName(NULL, executablePathAsArray, _MAX_PATH - 1);

		std::string executablePath = executablePathAsArray;
		std::string assetFolder = "assets";

		std::string resourceDirectory = executablePath;

		int positionOfParentDirectory = resourceDirectory.find_last_of("/\\");

		bool assetPathFound = false;
		while (positionOfParentDirectory > 0 && !assetPathFound)
		{
			resourceDirectory = resourceDirectory.substr(0, positionOfParentDirectory);

			DWORD dwAttrib = GetFileAttributes((resourceDirectory + "/" + assetFolder).c_str());
			if (dwAttrib != INVALID_FILE_ATTRIBUTES && (dwAttrib & FILE_ATTRIBUTE_DIRECTORY))
			{
				assetPathFound = true;
				m_assetFolderPath = resourceDirectory + "/" + assetFolder + "\//";
			}

			positionOfParentDirectory = resourceDirectory.find_last_of("/\\");
		}

		return assetPathFound;
	}

	void AssetManager::initialize(shared<AssetManager> _self, shared<Core> _core)
	{
		m_self = _self;
		m_core = _core;

		if (!findAssetFolder())
		{
			throw Exception("ASSET FOLDER NOT FOUND");
		}
	}
	shared<Core> AssetManager::getCore()
	{
		return m_core.lock();
	}
}
