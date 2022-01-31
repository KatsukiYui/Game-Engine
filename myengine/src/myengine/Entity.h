#include "MemoryDefines.h"
#include <vector>

namespace myengine
{
	class Component;
	class Core;
	class Transform;

	class Entity
	{
	private:
		std::vector<shared<Component> > m_components;
		weak<Transform> m_transform;
		weak<Core> m_core;
		weak<Entity> m_self;

	public:
		void initialize(shared<Entity> _self, shared<Core> _core);

		template <typename T>
		shared<T> addComponent()
		{
			shared<T> rtn = std::make_shared<T>();
			rtn->initialize(rtn, m_self.lock());

			m_components.push_back(rtn);
			return rtn;
		}

		void deleteComponent(shared<Component> _component);
		shared<Core> getCore();
		shared<Transform> getTransform();
		void update();

	};

}