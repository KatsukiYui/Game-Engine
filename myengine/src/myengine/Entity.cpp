#include "Entity.h"
namespace myengine
{
	shared<Entity> Core::initialize(shared<Core> _core)
	{
		shared<Entity> rtn = std::make_shared<Entity>();
		rtn->self = rtn;
		core = _core;
		return rtn;
	}

	shared<Component> addComponent()
	{
		shared<Component> rtn = std::make_shared<Component>();
		Components.push_back(rtn);
		return rtn;
	}

	shared<Core> Core::getCore()
	{
		return core;
	}
}