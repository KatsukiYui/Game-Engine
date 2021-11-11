#pragma once
#include "Component.h"

namespace myengine
{
	class Transform : Component
	{
	public: 

		//add an initialize override maybe?

		///////////insert complicated opengl shit here

		void update() override;
	};
}