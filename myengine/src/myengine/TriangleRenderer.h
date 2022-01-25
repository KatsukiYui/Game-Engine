#include "myengine/Component.h"

namespace myengine
{
	class TriangleRenderer : Component
	{
	public: 

		//add an initialize override maybe?

		///////////insert complicated opengl shit here

		void update() override;
	};
}