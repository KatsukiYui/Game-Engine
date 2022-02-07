#include "myengine/MyEngine.h"

class Cat : public Component
{
private:
	shared<AudioSource> m_catMeow;
public:
	void postInitialize(shared<Component> _self, shared<Entity> _entity) override;
	void play();
};