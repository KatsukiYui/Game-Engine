#include "Entity.h"
#include "Component.h"
#include "Core.h"
#include "Debugger.h"
#include "Transform.h"

namespace myengine
{
	void Entity::initialize(shared<Entity> _self, shared<Core> _core)
	{
		m_self = _self;
		//adding a transform component by default
		_self->m_transform = _self->addComponent<Transform>();
		m_core = _core;
	}

	void Entity::deleteComponent(shared<Component> _component)
	{
		std::vector<shared<Component>>::iterator it;
		it = std::find(m_components.begin(), m_components.end(), _component);

		if (it != m_components.end())
		{
			m_components.erase(it);
		}
		else
		{
			Debugger::printError("Component Not Found");
		}
	}

	shared<Core> Entity::getCore()
	{
		return m_core.lock();
	}

	shared<Transform> Entity::getTransform()
	{
		return m_transform.lock();
	}

	void Entity::update()
	{
		//Update each component?
		for (size_t ei = 0; ei < m_components.size(); ++ei)
		{
			m_components.at(ei)->update();
		}
	}
}