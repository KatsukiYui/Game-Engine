#ifndef H_COMPONENT
#define H_COMPONENT

#include "MemoryDefines.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace myengine
{
	class Entity;
	class Transform;

	/** Part of an entity E.g. Transform.
	* @see Transform.h */
	class Component
	{
	protected:
		weak<Entity> m_entity;
		weak<Transform> m_transform;
		weak<Component> m_self;

	public:
		/** Sets the member pointers. */
		void initialize(shared<Component> _self, shared<Entity> _entity);

		/** For components the need extra init steps.
		* @see Camera::postInitialize() */
		virtual void postInitialize(shared<Component> _self, shared<Entity> _entity);

		shared<Entity> getEntity(); /**< Getter */
		shared<Transform> getTransform(); /**< Getter */

		/** Update values. Called from the Entity::update() function.
		* Overriden in child classes*/
		virtual void update();
		/** Draw the component. Called from the Entity::render() function.
		* Overriden in child classes. */
		virtual void render(glm::mat4 _viewMatrix, glm::mat4 _projMatrix);
	};

}
#endif