#include "Component.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace myengine
{
	class Transform : public Component
	{

	private:
		glm::vec3 m_position;
		glm::quat m_rotation;
		glm::vec3 m_scale;
	public: 

		//add an initialize override maybe?

		///////////insert complicated opengl shit here

		void update() override;

		glm::mat4 getModelMatrix();
	};
}