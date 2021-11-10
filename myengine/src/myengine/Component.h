#pragma once
#include "Entity.h"

namespace myengine
{

	class Component
	{
	public:
		shared<Component> Initialize(shared<Entity> _entity);
		shared<Entity> getEntity();

	private:
		weak<Entity> entity;
		weak<Component> self;
	};

}