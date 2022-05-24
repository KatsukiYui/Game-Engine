#include "Component.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <mutex>

namespace myengine
{
	/** The transform component of an entity. Used to scale, move and rotate it. */
	class Transform : public Component
	{
	protected:
		std::mutex m_accessLock;

		glm::vec3 m_position;
		glm::quat m_rotation;
		glm::vec3 m_scale = glm::vec3(1);

	public: 
		void update() override;

		void setTransform(glm::vec3 _position, glm::quat _rotation, glm::vec3 _scale); /**< Setter */
		void setPosition(glm::vec3 _position); /**< Setter */
		void setRotation(glm::quat _rotation); /**< Setter */
		void setScale(glm::vec3 _scale); /**< Setter */

		glm::vec3 getPosition(); /**< Getter */
		glm::quat getRotation(); /**< Getter */
		glm::vec3 getScale(); /**< Getter */

		/** Creates and returns the model matrix from the entity's position, rotation & scale. */
		glm::mat4 getModelMatrix();
	};
}