#include "Entity.h"
#include "Component.h"

namespace myengine
{
	shared<Entity> myengine::Entity::initialize(shared<Core> _core)
	{
		shared<Entity> rtn = std::make_shared<Entity>();
		rtn->self = rtn;
		core = _core;
		return rtn;
	}

	shared<Component> myengine::Entity::addComponent()
	{
		shared<Component> rtn = std::make_shared<Component>();
		Components.push_back(rtn);
		return rtn;
	}

	shared<Core> myengine::Entity::getCore()
	{
		return core;
	}
}