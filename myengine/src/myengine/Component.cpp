#include "Component.h"

namespace myengine
{
	shared<Component> Component::initialize(shared<Entity> _entity)
	{
		shared<Component> rtn = std::make_shared<Component>();
		rtn->self = rtn;
		entity = _entity;
		return rtn;
	}

	shared<Entity> Component::getEntity()
	{
		return entity;
	}
}
