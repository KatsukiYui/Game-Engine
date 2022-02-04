#include "Transform.h"
#include <glm/ext.hpp>


namespace myengine
{
	void Transform::update()
	{
		//fml
	}

	void Transform::setTransform(glm::vec3 _position, glm::quat _rotation, glm::vec3 _scale)
	{
		m_position = _position;
		m_rotation = _rotation;
		m_scale = _scale;
	}

	void Transform::setPosition(glm::vec3 _position)
	{
		m_position = _position;
	}

	void Transform::setRotation(glm::quat _rotation)
	{
		m_rotation = _rotation;
	}

	void Transform::setScale(glm::vec3 _scale)
	{
		m_scale = _scale;
	}

	glm::vec3 Transform::getPosition()
	{
		return m_position;
	}

	glm::quat Transform::getRotation()
	{
		return m_rotation;
	}

	glm::vec3 Transform::getScale()
	{
		return m_scale;
	}

	glm::mat4 Transform::getModelMatrix()
	{
		glm::mat4x4 scaleMatrix = glm::scale(glm::identity<glm::mat4x4>(), m_scale);
		glm::mat4x4 rotationMatrix = glm::mat4_cast(m_rotation);
		glm::mat4x4 translationMatrix = glm::translate(glm::identity<glm::mat4x4>(), m_position);

		return translationMatrix * rotationMatrix * scaleMatrix;
	}
}