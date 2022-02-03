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


	core->start();

	return 0;
}