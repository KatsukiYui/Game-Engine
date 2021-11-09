#include "Entity.h"

namespace myengine
{

	class Component
	{
	public:
		static shared<Component> initialize(shared<Entity> _entity);
		shared<Entity> getEntity();

	private:
		weak<Entity> entity;
		weak<Component> self;
	};

}