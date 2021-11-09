#include "Core.h"
#include "Entity.h"
#include <SDL2/SDL.h>

namespace myengine
{
	shared<Core> Core::initialize()
	{
		shared<Core> rtn = std::make_shared<Core>();
		rtn->m_self = rtn;
		return rtn;
	}

	void Core::start()
	{
		while (!m_stop)
		{
			// Update world    //change this to iterator
			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				//m_entities.at(ei)->tick();
			}
			// Render world    
			// Post-render world
		}
	}

	shared<Entity> Core::addEntity()
	{
		shared<Entity> rtn = Entity::Initialize(m_self);
		entities.push_back(rtn);
		return rtn;
	}

}