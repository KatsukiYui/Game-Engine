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
	shared<Component> component = entity->addComponent();
	return 0;
}