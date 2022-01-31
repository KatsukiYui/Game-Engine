#include "Component.h"
#include "Entity.h"

namespace myengine
{
	void Component::initialize(shared<Component> _self, shared<Entity> _entity)
	{
		m_self = _self;
		m_entity = _entity;
		m_transform = _entity->getTransform();
	}

	shared<Entity> Component::getEntity()
	{
		return m_entity.lock();
	}

	shared<Transform> Component::getTransform()
	{
		return m_transform.lock();
	}

	void Component::update()
	{

	}
}
