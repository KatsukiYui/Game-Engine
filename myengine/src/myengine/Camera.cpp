#include "Camera.h"
#include "Entity.h"
#include "Core.h"

namespace myengine
{
	glm::mat4 Camera::getProjectionMatrix(float _screenWidth, float _screenLength)
	{
		glm::mat4 projectionMatrix = glm::perspective(glm::radians(45.0f), (_screenWidth / _screenLength), 0.25f, 5000.0f);
		return projectionMatrix;
	}

	void Camera::postInitialize(shared<Component> _self, shared<Entity> _entity)
	{
		_entity->getCore()->addCamera(std::dynamic_pointer_cast<Camera>(_self));
	}

	void Camera::preDestructor()
	{
		getEntity()->getCore()->deleteCamera(std::dynamic_pointer_cast<Camera>(m_self.lock()));
	}
}
