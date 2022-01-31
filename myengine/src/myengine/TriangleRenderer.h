#include "Component.h"

namespace myengine
{
	class TriangleRenderer : public Component
	{
	public: 

		//add an initialize override maybe?

		///////////insert complicated opengl shit here

		void update() override;
	};
}