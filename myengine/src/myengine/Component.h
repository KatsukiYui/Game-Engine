#ifndef H_COMPONENT
#define H_COMPONENT

#include "MemoryDefines.h"

namespace myengine
{
	class Entity;
	class Transform;
	class Component
	{
	private:
		weak<Entity> m_entity;
		weak<Transform> m_transform;
		weak<Component> m_self;

	public:
		virtual void initialize(shared<Component> _self, shared<Entity> _entity);
		shared<Entity> getEntity();
		shared<Transform> getTransform();
		virtual void update();
	};

}
#endif