#include "myengine/MyEngine.h"

class Rotator : public Component
{
private:
	float m_rotation = 0;
public:
	void update() override;
};