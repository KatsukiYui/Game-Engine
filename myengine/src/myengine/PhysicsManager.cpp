#include "PhysicsManager.h"
#include "Core.h"
#include "SphereCollider.h"

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

	void PhysicsManager::addSphereCollider(shared<SphereCollider> _collider)
	{
		m_sphereColliders.push_back(_collider);
	}
}