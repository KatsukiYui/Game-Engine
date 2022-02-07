#include "myengine/MyEngine.h"

class Heart : public Component
{
private:
	float m_timer = 1.0f;
public:
	void update() override;
};