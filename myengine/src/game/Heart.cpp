#include "Heart.h"



void Heart::update()
{
	float deltaTime = getEntity()->getCore()->getDeltaTime();

	shared<Transform> transform = m_transform.lock();
	transform->setPosition(transform->getPosition() + (glm::vec3(0, 0.25f, 0) * deltaTime));
	transform->setScale(transform->getScale() * (1.0f + (0.5f * deltaTime)));

	m_timer -= deltaTime;
	if (m_timer < 0)
	{
		getEntity()->getCore()->deleteEntity(getEntity());
	}
}