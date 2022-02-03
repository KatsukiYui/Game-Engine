#ifndef H_ASSET
#define H_ASSET

#include <string>

namespace myengine
{
	/** Parent class of all assets/resources.
	* @see Mesh.h	*/
	class Asset
	{
	protected:
		/** Stores the file name for the asset without the path. */
		std::string m_fileName;

	public:
		/** Loads the asset/resource from the asset folder.
		* Is overriden by different assets.
		* Called by the asset manager.
		* @see AssetManager.h
		* @param _assetFolderPath: The path of the asset folder. Stored in the asset manager.
		* @param _fileName: The actual name of the asset file.*/
		virtual void loadAsset(std::string _assetFolderPath, std::string _fileName); 
	};
}

#endif