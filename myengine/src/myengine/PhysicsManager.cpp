#include <glm/gtx/intersect.hpp>
#include "PhysicsManager.h"
#include "Core.h"
#include "SphereCollider.h"
#include "Debugger.h"
#include "Transform.h"

namespace myengine
{
	void PhysicsManager::initialize(shared<PhysicsManager> _self, shared<Core> _core)
	{
		m_self = _self;
		m_core = _core;
	}

	shared<Core> PhysicsManager::getCore()
	{
		return m_core.lock();
	}

	std::vector<shared<SphereCollider>> PhysicsManager::checkSphereCollisions(shared<SphereCollider> _collider)
	{
		std::vector<shared<SphereCollider>> rtn;
		for (shared<SphereCollider> collider : m_sphereColliders)
		{
			// do not check against itself
			if (_collider->getEntity() != collider->getEntity())
			{
				// check if the passed collider collides with this sphere
				if (_collider->isColliding(collider))
				{
					rtn.push_back(collider);
				}
			}
		}

		return rtn;
	}

	std::vector<shared<SphereCollider>> PhysicsManager::checkSphereCollisions(Ray &_ray)
	{
		std::vector<shared<SphereCollider>> rtn;
		glm::vec3 centre;
		float radius;
		glm::vec3 intersection;
		glm::vec3 normal;

		for (shared<SphereCollider> collider : m_sphereColliders)
		{
			centre = collider->getTransform()->getPosition();
			radius = collider->getRadius();

			// using glm's ray sphere intersection function which returns a bool
			if (glm::intersectRaySphere(_ray.m_origin, _ray.m_direction, centre, radius, intersection, normal))
			{
				rtn.push_back(collider);
			}
		}

		return rtn;
	}

	void PhysicsManager::addSphereCollider(shared<SphereCollider> _collider)
	{
		m_sphereColliders.push_back(_collider);
	}

	void PhysicsManager::deleteSphereCollider(shared<SphereCollider> _collider)
	{
		std::vector<shared<SphereCollider>>::iterator it;
		it = std::find(m_sphereColliders.begin(), m_sphereColliders.end(), _collider);

		if (it != m_sphereColliders.end())
		{
			m_sphereColliders.erase(it);
		}
		else
		{
			Debugger::printError("Sphere Collider Not Found");
		}

	}
}