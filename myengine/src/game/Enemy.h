#include "myengine/MyEngine.h"

class Enemy : public Component
{
private:
	shared<AudioSource> m_death;
	float m_timer = 0.2f;
public:
	void postInitialize(shared<Component> _self, shared<Entity> _entity) override;
	void play();
};