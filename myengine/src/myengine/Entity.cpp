#include "Entity.h"
#include "Component.h"

namespace myengine
{
	shared<Entity> Entity::Initialize(shared<Core> _core)
	{
		shared<Entity> rtn = std::make_shared<Entity>();
		rtn->self = rtn;
		core = _core;
		return rtn;
	}

	shared<Component> Entity::addComponent()
	{
		shared<Component> rtn = std::make_shared<Component>();
        rtn->Initialize(self.lock());
		Components.push_back(rtn);
		return rtn;
	}

	shared<Core> Entity::getCore()
	{
		return core.lock();
	}
}