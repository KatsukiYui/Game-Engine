#include "myengine/MyEngine.h"

class PlayerController : public Component
{
private:
	weak<InputManager> m_inputManager;
	weak<PhysicsManager> m_physicsManager;

	float m_speed = 0.05f;
	float m_lookSpeed = 0.005f;

	float m_cameraX = 0.0f;
	float m_cameraY = 0.0f;
public:
	void postInitialize(shared<Component> _self, shared<Entity> _entity) override;
	void update() override;
}; 