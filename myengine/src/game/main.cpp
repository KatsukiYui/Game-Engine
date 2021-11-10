#include "myengine/MyEngine.h"

int main()
{
	shared<Core> core = Core::initialize();
	shared<Entity> entity = core->addEntity();
	shared<Component> component = entity->addComponent();
	return 0;
}