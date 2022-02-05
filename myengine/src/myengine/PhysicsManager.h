#include <string>
#include <vector>
#include "MemoryDefines.h"

namespace myengine
{
	class Core;
	class Component;
	class SphereCollider;

	class PhysicsManager
	{
	private:
		std::vector<shared<SphereCollider>> m_sphereColliders;
		weak<PhysicsManager> m_self;
		weak<Core> m_core;

	public:
		void initialize(shared<PhysicsManager> _self, shared<Core> _core);

		shared<Core> getCore(); /**< Getter */

		std::vector<shared<SphereCollider>> checkSphereCollisions(shared<SphereCollider> _collider);

		void addSphereCollider(shared<SphereCollider> _collider);

	};
}

