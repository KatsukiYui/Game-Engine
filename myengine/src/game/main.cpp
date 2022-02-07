#include "myengine/MyEngine.h"
#include "PlayerController.h"
#include "Cat.h"
#include "Rotator.h"

#include <iostream>


void initializeGame(shared<Core> _core);

int main()
{
	#ifdef DEBUG
		std::cout << "Debug" << std::endl;
	#else
		std::cout << "Release" << std::endl;
	#endif // DEBUG

	shared<Core> core = Core::initialize();

	initializeGame(core);

	/*
	shared<Entity> camera_1 = core->addEntity();
	//shared<Entity> camera_2 = core->addEntity();
	shared<Camera> cameraComponent_1 = camera_1->addComponent<Camera>();
	//shared<Camera> cameraComponent_2 = camera_2->addComponent<Camera>();
	cameraComponent_1->getTransform()->setTransform(glm::vec3(0, 0, -5), glm::quat(1, 0, 0, 0), glm::vec3(1.0f, 1.0f, 1.0f));
	//cameraComponent_2->getTransform()->setTransform(glm::vec3(0, 0, - 5), glm::quat(1, 0, 0, 0), glm::vec3(1, 1, 1));
	shared<AudioListener> audioListener = camera_1->addComponent<AudioListener>();
	//camera_1->deleteComponent(cameraComponent_1);
	//camera_2->deleteComponent(cameraComponent_2);

	shared<AudioSource> BGM = camera_1->addComponent<AudioSource>();
	BGM->setAudio(core->getAssetManager()->getAsset<Audio>("Danganronpa.ogg"));
	BGM->setLooping(true);
	BGM->play(0.2);
	*/

	/*
	//Test Zone Keep Out

	shared<Entity> sphere_1 = core->addEntity();
	shared<Entity> sphere_2 = core->addEntity();
	shared<SphereCollider> sphereColliderComponent_1 = sphere_1->addComponent<SphereCollider>();
	shared<SphereCollider> sphereColliderComponent_2 = sphere_2->addComponent<SphereCollider>();
	
	sphereColliderComponent_1->setRadius(0.5f);
	sphereColliderComponent_2->setRadius(0.5f);

	sphereColliderComponent_1->getTransform()->setTransform(glm::vec3(0.0f, 0, 0), glm::quat(1, 0, 0, 0), glm::vec3(1, 1, 1));
	sphereColliderComponent_2->getTransform()->setTransform(glm::vec3(0.0f, 0, 0), glm::quat(1, 0, 0, 0), glm::vec3(1, 1, 1));

	std::vector<shared<SphereCollider>> myVectorSupaaaahCool = core->getPhysicsManager()->checkSphereCollisions(sphereColliderComponent_2);
	if (myVectorSupaaaahCool.size() > 0)
	{
		Debugger::printLog("SCREAM.. in circle. 1: " + std::to_string((int)myVectorSupaaaahCool.size()) + ".");
	}

	std::vector<shared<SphereCollider>> my_Vector_SupaaaahCool = core->getPhysicsManager()->checkSphereCollisions(Ray(glm::vec3(0.49f, 0, 10), glm::vec3(0, 0, -1)));
	if (my_Vector_SupaaaahCool.size() > 0)
	{
		Debugger::printLog("SCREAM.. in rays. 1");
	}


	sphere_1->deleteComponent(sphereColliderComponent_1);


	myVectorSupaaaahCool = core->getPhysicsManager()->checkSphereCollisions(sphereColliderComponent_2);
	if (myVectorSupaaaahCool.size() > 0)
	{
		Debugger::printLog("SCREAM.. in circle. 2: " + std::to_string((int) myVectorSupaaaahCool.size()) + ".");
	}

	my_Vector_SupaaaahCool = core->getPhysicsManager()->checkSphereCollisions(Ray(glm::vec3(0.49f, 0, 10), glm::vec3(0, 0, -1)));
	if (my_Vector_SupaaaahCool.size() > 0)
	{
		Debugger::printLog("SCREAM.. in rays. 2");
	}


	sphere_2->deleteComponent(sphereColliderComponent_2);


	myVectorSupaaaahCool = core->getPhysicsManager()->checkSphereCollisions(sphereColliderComponent_2);
	if (myVectorSupaaaahCool.size() > 0)
	{
		Debugger::printLog("SCREAM.. in circle. 3");
	}

	my_Vector_SupaaaahCool = core->getPhysicsManager()->checkSphereCollisions(Ray(glm::vec3(0.49f, 0, 10), glm::vec3(0, 0, -1)));
	if (my_Vector_SupaaaahCool.size() > 0)
	{
		Debugger::printLog("SCREAM.. in rays. 3");
	}

	*/

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