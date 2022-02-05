#include "SphereCollider.h"
#include "Transform.h"
#include "glm/glm.hpp"
namespace myengine
{
	void SphereCollider::postInitialize(shared<Component> _self, shared<Entity> _entity)
	{
	}

	bool SphereCollider::isColliding(shared<SphereCollider> _collider)
	{
		// the distance between the sphere centres
		float distance = glm::distance((_collider->getTransform()->getPosition()), (this->getTransform()->getPosition()));

		if (distance <= (m_radius + _collider->getRadius()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void SphereCollider::setRadius(float _radius)
	{
		m_radius = _radius;
	}

	float SphereCollider::getRadius()
	{
		return m_radius;
	}
}
