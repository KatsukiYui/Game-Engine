#include <string>
#include <vector>
#include <glm/glm.hpp>
#include "MemoryDefines.h"

namespace myengine
{
	class Core;
	class Component;
	class SphereCollider;

	struct Ray
	{
		glm::vec3 origin;
		glm::vec3 direction;
	};

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

		std::vector<shared<SphereCollider>> checkSphereCollisions(Ray &_ray);

		void addSphereCollider(shared<SphereCollider> _collider);

	};
}

