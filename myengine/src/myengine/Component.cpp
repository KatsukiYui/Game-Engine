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

	void Component::postInitialize(shared<Component> _self, shared<Entity> _entity)
	{
	}

	void Component::preDestructor()
	{
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

	void Component::render(glm::mat4 _viewMatrix, glm::mat4 _projMatrix)
	{

	}
}
