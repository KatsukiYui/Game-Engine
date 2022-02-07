#include "Rotator.h"

void Rotator::update()
{
	m_rotation += 0.01f;
	getTransform()->setRotation(glm::quat(glm::vec3(0, m_rotation, 0)));
}