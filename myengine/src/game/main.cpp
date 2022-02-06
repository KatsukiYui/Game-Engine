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
	meshRenderer->setShader(core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_NoTexture.txt"));

	shared<Entity> camera = core->addEntity();
	shared<Camera> cameraComponent = camera->addComponent<Camera>();
	cameraComponent->getTransform()->setTransform(glm::vec3(0, 0, -15), glm::quat(1, 0, 0, 0), glm::vec3(1, 1, 1));
	shared<AudioListener> audioListener = camera->addComponent<AudioListener>();
	shared<AudioSource> BGM = camera->addComponent<AudioSource>();
	BGM->setAudio(core->getAssetManager()->getAsset<Audio>("Danganronpa.ogg"));
	BGM->setLooping(true);
	BGM->play(0.2);

	core->start();

	return 0;
}