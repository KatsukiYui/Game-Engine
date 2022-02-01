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

	shared<Entity> entity = core->addEntity();
	shared<MeshRenderer> meshRenderer = entity->addComponent<MeshRenderer>();
	meshRenderer->setMesh(core->getAssetManager()->getAsset<Mesh>("teapot.obj"));
	meshRenderer->setShader(core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_NoTexture.txt"));
	
	core->start();

	return 0;
}