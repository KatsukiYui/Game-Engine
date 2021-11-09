#include "Component.h"

shared<Component> myengine::Component::initialize(shared<Entity> _entity)
{
	shared<Component> rtn = std::make_shared<Component>();
	rtn->self = rtn;
	entity = _ent;
	return rtn;
}

shared<Entity> myengine::Component::getEntity()
{
	return entity;
}
