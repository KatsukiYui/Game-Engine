#pragma once
#include "Entity.h"

namespace myengine
{

	class Component
	{
	public:
		/////make this a template
		virtual shared<Component> initialize(shared<Entity> _entity);
		shared<Entity> getEntity();
		virtual void update() = 0;

	private:
		weak<Entity> m_entity;
		weak<Component> m_self;
	};

}