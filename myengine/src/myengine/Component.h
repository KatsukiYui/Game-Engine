#ifndef H_COMPONENT
#define H_COMPONENT

#include "MemoryDefines.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace myengine
{
	class Entity;
	class Transform;
	class Component
	{
	protected:
		weak<Entity> m_entity;
		weak<Transform> m_transform;
		weak<Component> m_self;

	public:
		virtual void initialize(shared<Component> _self, shared<Entity> _entity);
		shared<Entity> getEntity();
		shared<Transform> getTransform();
		virtual void update();
		virtual void render(glm::mat4 _viewMatrix, glm::mat4 _projMatrix);
	};

}
#endif