#include "Component.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace myengine
{
	class Transform : Component
	{

	private:
		glm::vec3 Position;
		glm::quat Rotation;
		glm::vec3 Scale;
	public: 

		//add an initialize override maybe?

		///////////insert complicated opengl shit here

		void update() override;

		glm::vec3 multiplyByModelMatrix(glm::vec3 _point);
	};
}