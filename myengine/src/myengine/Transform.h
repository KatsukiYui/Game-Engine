#include "Component.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace myengine
{
	/** The transform component of an entity. Used to scale, move and rotate it. */
	class Transform : public Component
	{
	protected:
		glm::vec3 m_position;
		glm::quat m_rotation;
		glm::vec3 m_scale = glm::vec3(1);

	public: 
		void update() override;
		void setTransform(glm::vec3 _position, glm::quat _rotation, glm::vec3 _scale);
		void setPosition(glm::vec3 _position);
		void setRotation(glm::quat _rotation);
		void setScale(glm::vec3 _scale);

		/** Creates and returns the model matrix from the entity's position, rotation & scale. */
		glm::mat4 getModelMatrix();
	};
}