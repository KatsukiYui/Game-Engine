#include "Component.h"

namespace myengine
{
	/**  */
	class Camera : public Component
	{
	protected:

	public:
		/**  */
		glm::mat4 getProjectionMatrix(float _screenWidth, float _screenLength);

		void postInitialize(shared<Component> _self, shared<Entity> _entity) override;
		void onDestroy() override;
	};
}
