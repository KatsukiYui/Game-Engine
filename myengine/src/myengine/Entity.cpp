#include "Entity.h"
#include "Component.h"

namespace myengine
{
	shared<Entity> Entity::initialize(shared<Core> _core)
	{
		shared<Entity> rtn = std::make_shared<Entity>();
		rtn->m_self = rtn;
		m_core = _core;
		return rtn;
	}

	shared<Component> Entity::addComponent()
	{
		shared<Component> rtn = std::make_shared<Component>();
        rtn->initialize(m_self.lock());
		m_components.push_back(rtn);
		return rtn;
	}

	shared<Core> Entity::getCore()
	{
		return m_core.lock();
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