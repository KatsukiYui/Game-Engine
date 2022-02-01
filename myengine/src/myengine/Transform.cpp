#include "Transform.h"
#include <glm/ext.hpp>


namespace myengine
{
	void Transform::update()
	{
		//fml
	}

	glm::mat4 Transform::getModelMatrix()
	{
		glm::mat4x4 scaleMatrix = glm::scale(glm::identity<glm::mat4x4>(), m_scale);
		glm::mat4x4 rotationMatrix = glm::mat4_cast(m_rotation);
		glm::mat4x4 translationMatrix = glm::translate(glm::identity<glm::mat4x4>(), m_position);

		return translationMatrix * rotationMatrix * scaleMatrix;
	}
}