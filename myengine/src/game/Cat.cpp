#include "Cat.h"
#include "Heart.h"

void Cat::postInitialize(shared<Component> _self, shared<Entity> _entity)
{
	m_catMeow = _entity->addComponent<AudioSource>();
	m_catMeow->setAudio(_entity->getCore()->getAssetManager()->getAsset<Audio>("CatMeow.ogg"));
}

void Cat::play()
{
	m_catMeow->play(0.5f);

	shared<Core> core = getEntity()->getCore();

	shared<Entity> heart = core->addEntity();
	shared<Heart> heartComponent = heart->addComponent<Heart>();
	shared<MeshRenderer> meshRenderer = heart->addComponent<MeshRenderer>();
	meshRenderer->setShader(core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	meshRenderer->setMesh(core->getAssetManager()->getAsset<Mesh>("heart.obj"));
	meshRenderer->setTexture(core->getAssetManager()->getAsset<Texture>("heart.bmp"));
	heart->getTransform()->setTransform(
		glm::vec3(getTransform()->getPosition() + glm::vec3(0, 0.5f, 0)),
		glm::quat(glm::vec3(0, 0, 0)),
		glm::vec3(0.01f, 0.01f, 0.01f)
	);
}