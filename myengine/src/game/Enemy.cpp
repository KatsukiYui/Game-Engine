#include "Enemy.h"


void Enemy::postInitialize(shared<Component> _self, shared<Entity> _entity)
{
	m_death = _entity->addComponent<AudioSource>();
	m_death->setAudio(_entity->getCore()->getAssetManager()->getAsset<Audio>("pew.ogg"));
}

void Enemy::play()
{
	//m_death->play(0.5f);

	shared<Core> core = getEntity()->getCore();

	float deltaTime = getEntity()->getCore()->getDeltaTime();

	m_timer -= deltaTime;
	//if (m_timer < 0)
	{
		getEntity()->getCore()->deleteEntity(getEntity());
	}



	//shared<Entity> heart = core->addEntity();
	//shared<Heart> heartComponent = heart->addComponent<Heart>();
	//shared<MeshRenderer> meshRenderer = heart->addComponent<MeshRenderer>();
	//meshRenderer->setShader(core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	//meshRenderer->setMesh(core->getAssetManager()->getAsset<Mesh>("heart.obj"));
	//meshRenderer->setTexture(core->getAssetManager()->getAsset<Texture>("heart.bmp"));
	//heart->getTransform()->setTransform(
	//	glm::vec3(getTransform()->getPosition() + glm::vec3(0, 0.5f, 0)),
	//	glm::quat(glm::vec3(0, 0, 0)),
	//	glm::vec3(0.01f, 0.01f, 0.01f)
	//);
}