#include "myengine/MyEngine.h"
#include <iostream>

int main()
{
	#ifdef DEBUG
		std::cout << "Debug" << std::endl;
	#else
		std::cout << "Release" << std::endl;
	#endif // DEBUG

	shared<Core> core = Core::initialize();



	shared<Entity> teapot = core->addEntity();
	shared<MeshRenderer> meshRenderer = teapot->addComponent<MeshRenderer>();
	meshRenderer->setMesh(core->getAssetManager()->getAsset<Mesh>("teapot.obj"));
	meshRenderer->setShader(core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	meshRenderer->setTexture(core->getAssetManager()->getAsset<Texture>("TeapotColourMap.bmp"));

	shared<Entity> camera_1 = core->addEntity();
	//shared<Entity> camera_2 = core->addEntity();
	shared<Camera> cameraComponent_1 = camera_1->addComponent<Camera>();
	//shared<Camera> cameraComponent_2 = camera_2->addComponent<Camera>();
	cameraComponent_1->getTransform()->setTransform(glm::vec3(0, 0, -5), glm::quat(1, 0, 0, 0), glm::vec3(1, 1, 1));
	//cameraComponent_2->getTransform()->setTransform(glm::vec3(0, 0, - 5), glm::quat(1, 0, 0, 0), glm::vec3(1, 1, 1));
	shared<AudioListener> audioListener = camera_1->addComponent<AudioListener>();
	//camera_1->deleteComponent(cameraComponent_1);
	//camera_2->deleteComponent(cameraComponent_2);

	shared<AudioSource> BGM = camera_1->addComponent<AudioSource>();
	BGM->setAudio(core->getAssetManager()->getAsset<Audio>("Danganronpa.ogg"));
	BGM->setLooping(true);
	BGM->play(0.2);



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



	core->start();

	return 0;
}