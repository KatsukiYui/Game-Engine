#include "PlayerController.h"
#include "Cat.h"
#include "Enemy.h"
#include <algorithm>

void PlayerController::postInitialize(shared<Component> _self, shared<Entity> _entity)
{
	m_inputManager = m_entity.lock()->getCore()->getInputManager();
	m_physicsManager = m_entity.lock()->getCore()->getPhysicsManager();

	m_pew = _entity->addComponent<AudioSource>();
	m_pew->setAudio(_entity->getCore()->getAssetManager()->getAsset<Audio>("pew.ogg"));
}

void PlayerController::update()
{
	shared<InputManager> inputManager = m_inputManager.lock();

	glm::vec3 positionOffset = glm::vec3(0);
	if (inputManager->getInput()->isKeyHeld(W))
	{
		positionOffset -= glm::vec3(0, 0, 1);
	}	
	if (inputManager->getInput()->isKeyHeld(A))
	{
		positionOffset -= glm::vec3(1, 0, 0);
	}
	if (inputManager->getInput()->isKeyHeld(S))
	{
		positionOffset += glm::vec3(0, 0, 1);
	}
	if (inputManager->getInput()->isKeyHeld(D))
	{
		positionOffset += glm::vec3(1, 0, 0);
	}

	glm::vec2 mouseDelta = inputManager->getInput()->getMousePosition();
	if (glm::length(mouseDelta) > 0)
	{
		shared<Transform> transform = getTransform();

		m_cameraX -= (m_lookSpeed * mouseDelta.x);
		m_cameraY += (m_lookSpeed * mouseDelta.y);

		m_cameraY = std::max(-1.0f, std::min(m_cameraY, 1.0f));

		glm::vec3 lookDirection = glm::vec3(
			sin(m_cameraX) * cos(m_cameraY),
			sin(m_cameraY),
			cos(m_cameraX) * cos(m_cameraY));

		transform->setRotation(glm::quatLookAt(-lookDirection, glm::vec3(0, 1, 0)));
	}


	if (glm::length(positionOffset) > 0)
	{
		shared<Transform> transform = getTransform();

		positionOffset = (transform->getRotation() * positionOffset);
		
		glm::vec3 positionFlattened = glm::normalize(glm::vec3(positionOffset.x, 0, positionOffset.z));
		positionFlattened *= m_speed;

		transform->setPosition(transform->getPosition() + positionFlattened);
	}
	/*
	if (inputManager->getInput()->isMouseDown(Left))
	{
		shared<Transform> transform = getTransform();

		Ray ray = Ray(transform->getPosition(), (transform->getRotation() * glm::vec3(0, 0, -1)));
		
		std::vector<shared<SphereCollider>> colliderList = m_physicsManager.lock()->checkSphereCollisions(ray);
		if (colliderList.size() > 0)
		{
			shared<Entity> hitEntity = colliderList[0]->getEntity();
			std::vector<shared<Cat>> catComponents = hitEntity->getComponent<Cat>();
			if (catComponents.size() > 0)
			{
				catComponents[0]->play();
			}
		}
	}
	*/

	if (inputManager->getInput()->isMouseDown(Left))
	{
		m_pew->play(0.25f);

		shared<Transform> transform = getTransform();
		Ray ray = Ray(transform->getPosition(), (transform->getRotation() * glm::vec3(0, 0, -1)));

		std::vector<shared<SphereCollider>> colliderList = m_physicsManager.lock()->checkSphereCollisions(ray);
		if (colliderList.size() > 0)
		{
			shared<Entity> hitEntity = colliderList[0]->getEntity();
			std::vector<shared<Enemy>> enemyComponents = hitEntity->getComponent<Enemy>();
			if (enemyComponents.size() > 0)
			{
				//enemyComponents[0]->play();
			}
		}

	}

	if (inputManager->getInput()->isMouseDown(Right))
	{

	}
}


void PlayerController::setCameraOffset(float _x, float _y)
{
	m_cameraX = _x; m_cameraY = _y; 
}

