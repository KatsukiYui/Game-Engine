#include "Component.h"
#include "MemoryDefines.h"

namespace myengine
{
	/**  */
	class SphereCollider : public Component
	{
	private:
		float m_radius = 0.5f;
	public:

		void postInitialize(shared<Component> _self, shared<Entity> _entity) override;
		void onDestroy();

		bool isColliding(shared<SphereCollider> _collider);

		void setRadius(float _radius);
		float getRadius();
	};
}

