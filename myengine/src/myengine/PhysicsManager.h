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
		Ray(glm::vec3 _origin, glm::vec3 _direction) { m_origin = _origin; m_direction = _direction; };
		glm::vec3 m_origin;
		glm::vec3 m_direction;
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

		void deleteSphereCollider(shared<SphereCollider> _collider);

	};
}
