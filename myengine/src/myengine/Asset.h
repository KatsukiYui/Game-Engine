#pragma once
#include <string>

namespace myengine
{
	class Asset
	{
	private:
		std::string m_fileName;
	public:
		//load fn
		virtual void loadAsset();

	};
}