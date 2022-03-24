#include "myengine/MyEngine.h"
#include "PlayerController.h"
#include "Cat.h"
#include "Enemy.h"
#include "Rotator.h"

#include <iostream>


void initializeGame(shared<Core> _core);
void initializeGame2(shared<Core> _core);

int main()
{
	#ifdef DEBUG
		std::cout << "Debug" << std::endl;
	#else
		std::cout << "Release" << std::endl;
	#endif // DEBUG

	shared<Core> core = Core::initialize();

	initializeGame2(core);

	core->start();

	return 0;
}

void initializeGame(shared<Core> _core)
{
	shared<Entity> player = _core->addEntity();
	shared<Camera> camera = player->addComponent<Camera>();
	shared<AudioListener> audioListener = player->addComponent<AudioListener>();
	shared<AudioSource> musicSource = player->addComponent<AudioSource>();
	musicSource->setAudio(_core->getAssetManager()->getAsset<Audio>("stardew.ogg"));
	musicSource->setLooping(true);
	musicSource->play(0.25f);
	player->getTransform()->setTransform(glm::vec3(0, 1.55, 2.5), glm::quat(1, 0, 0, 0), glm::vec3(1.0f, 1.0f, 1.0f));
	shared<PlayerController> playerController = player->addComponent<PlayerController>();


	shared<Entity> room = _core->addEntity();
	shared<MeshRenderer> roomMeshRenderer = room->addComponent<MeshRenderer>();
	roomMeshRenderer->setShader(_core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	roomMeshRenderer->setMesh(_core->getAssetManager()->getAsset<Mesh>("room.obj"));
	roomMeshRenderer->setTexture(_core->getAssetManager()->getAsset<Texture>("room.bmp"));
	room->getTransform()->setTransform(glm::vec3(0, 0, 0), glm::quat(glm::vec3(0, 0, 0)), glm::vec3(0.5f, 0.5f, 0.5f));



	shared<Entity> cat1 = _core->addEntity();
	shared<Rotator> rotator = cat1->addComponent<Rotator>();
	shared<MeshRenderer> meshRenderer1 = cat1->addComponent<MeshRenderer>();
	shared<SphereCollider> catCollider1 = cat1->addComponent<SphereCollider>();
	shared<Cat> catComponent1 = cat1->addComponent<Cat>();
	meshRenderer1->setShader(_core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	meshRenderer1->setMesh(_core->getAssetManager()->getAsset<Mesh>("cat.obj"));
	meshRenderer1->setTexture(_core->getAssetManager()->getAsset<Texture>("blackCat.bmp"));
	cat1->getTransform()->setTransform(glm::vec3(1, 0, 1.5), glm::quat(glm::vec3(0, 1.0f, 0)), glm::vec3(0.005f, 0.005f, 0.005f));

	shared<Entity> cat2 = _core->addEntity();
	shared<MeshRenderer> meshRenderer2 = cat2->addComponent<MeshRenderer>();
	shared<SphereCollider> catCollider2 = cat2->addComponent<SphereCollider>();
	shared<Cat> catComponent2 = cat2->addComponent<Cat>();
	meshRenderer2->setShader(_core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	meshRenderer2->setMesh(_core->getAssetManager()->getAsset<Mesh>("cat.obj"));
	meshRenderer2->setTexture(_core->getAssetManager()->getAsset<Texture>("pinkCat.bmp"));
	cat2->getTransform()->setTransform(glm::vec3(-1.2, 0, 1), glm::quat(glm::vec3(0, 1.2f, 0)), glm::vec3(0.005f, 0.005f, 0.005f));

	shared<Entity> cat3 = _core->addEntity();
	shared<MeshRenderer> meshRenderer3 = cat3->addComponent<MeshRenderer>();
	shared<SphereCollider> catCollider3 = cat3->addComponent<SphereCollider>();
	shared<Cat> catComponent3 = cat3->addComponent<Cat>();
	meshRenderer3->setShader(_core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	meshRenderer3->setMesh(_core->getAssetManager()->getAsset<Mesh>("cat.obj"));
	meshRenderer3->setTexture(_core->getAssetManager()->getAsset<Texture>("orangeCat.bmp"));
	cat3->getTransform()->setTransform(glm::vec3(0.8, 0, -1.2), glm::quat(glm::vec3(0, 0.5f, 0)), glm::vec3(0.005f, 0.005f, 0.005f));

	shared<Entity> cat4 = _core->addEntity();
	shared<MeshRenderer> meshRenderer4= cat4->addComponent<MeshRenderer>();
	shared<SphereCollider> catCollider4 = cat4->addComponent<SphereCollider>();
	shared<Cat> catComponent4 = cat4->addComponent<Cat>();
	meshRenderer4->setShader(_core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	meshRenderer4->setMesh(_core->getAssetManager()->getAsset<Mesh>("cat.obj"));
	meshRenderer4->setTexture(_core->getAssetManager()->getAsset<Texture>("crazyCat.bmp"));
	cat4->getTransform()->setTransform(glm::vec3(-1.7, 0, -1.1), glm::quat(glm::vec3(0, 0.2f, 0)), glm::vec3(0.005f, 0.005f, 0.005f));
}

void initializeGame2(shared<Core> _core)
{
	shared<Entity> player = _core->addEntity();
	shared<Camera> camera = player->addComponent<Camera>();
	shared<AudioListener> audioListener = player->addComponent<AudioListener>();
	shared<AudioSource> musicSource = player->addComponent<AudioSource>();
	musicSource->setAudio(_core->getAssetManager()->getAsset<Audio>("stardew.ogg"));
	musicSource->setLooping(true);
	musicSource->play(0.25f);
	player->getTransform()->setTransform(glm::vec3(0, 1.55, 2.5), glm::quat(1, 0, 0, 0), glm::vec3(1.0f, 1.0f, 1.0f));
	shared<PlayerController> playerController = player->addComponent<PlayerController>();


	shared<Entity> room = _core->addEntity();
	shared<MeshRenderer> roomMeshRenderer = room->addComponent<MeshRenderer>();
	roomMeshRenderer->setShader(_core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	roomMeshRenderer->setMesh(_core->getAssetManager()->getAsset<Mesh>("room.obj"));
	roomMeshRenderer->setTexture(_core->getAssetManager()->getAsset<Texture>("room.bmp"));
	room->getTransform()->setTransform(glm::vec3(0, 0, 0), glm::quat(glm::vec3(0, 0, 0)), glm::vec3(0.7f, 0.7f, 0.7f));

	//Enemies

	shared<Entity> target1 = _core->addEntity();
	shared<MeshRenderer> meshRenderer1 = target1->addComponent<MeshRenderer>();
	shared<SphereCollider> targetCollider1 = target1->addComponent<SphereCollider>();
	shared<Enemy> enemyComponent1 = target1->addComponent<Enemy>();
	meshRenderer1->setShader(_core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	meshRenderer1->setMesh(_core->getAssetManager()->getAsset<Mesh>("target.obj"));
	meshRenderer1->setTexture(_core->getAssetManager()->getAsset<Texture>("target.bmp"));
	target1->getTransform()->setTransform(glm::vec3(2, 2, 1), glm::quat(glm::vec3(0, 0, 0)), glm::vec3(0.01f, 0.01f, 0.01f));

	shared<Entity> target2 = _core->addEntity();
	shared<MeshRenderer> meshRenderer2 = target2->addComponent<MeshRenderer>();
	shared<SphereCollider> targetCollider2 = target2->addComponent<SphereCollider>();
	shared<Enemy> enemyComponent2 = target2->addComponent<Enemy>();
	meshRenderer2->setShader(_core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	meshRenderer2->setMesh(_core->getAssetManager()->getAsset<Mesh>("target.obj"));
	meshRenderer2->setTexture(_core->getAssetManager()->getAsset<Texture>("target.bmp"));
	target2->getTransform()->setTransform(glm::vec3(1, 1, 1), glm::quat(glm::vec3(0, 0, 0)), glm::vec3(0.01f, 0.01f, 0.01f));

	shared<Entity> target3 = _core->addEntity();
	shared<MeshRenderer> meshRenderer3 = target3->addComponent<MeshRenderer>();
	shared<SphereCollider> targetCollider3 = target3->addComponent<SphereCollider>();
	shared<Enemy> enemyComponent3 = target3->addComponent<Enemy>();
	meshRenderer3->setShader(_core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	meshRenderer3->setMesh(_core->getAssetManager()->getAsset<Mesh>("target.obj"));
	meshRenderer3->setTexture(_core->getAssetManager()->getAsset<Texture>("target.bmp"));
	target3->getTransform()->setTransform(glm::vec3(2, 1, 1), glm::quat(glm::vec3(0, 0, 0)), glm::vec3(0.01f, 0.01f, 0.01f));

}