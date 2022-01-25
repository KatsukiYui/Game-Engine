#ifndef H_COMPONENT
#define H_COMPONENT

#include "MemoryDefines.h"

namespace myengine
{
	class Entity;
	class Component
	{
	public:
		/////make this a template
		virtual shared<Component> initialize(shared<Entity> _entity);
		shared<Entity> getEntity();
		virtual void update();

	private:
		weak<Entity> m_entity;
		weak<Component> m_self;
	};

}
#endif