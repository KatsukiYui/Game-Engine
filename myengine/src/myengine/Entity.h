#include "MemoryDefines.h"
#include <vector>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace myengine
{
	class Component;
	class Core;
	class Transform;

	class Entity
	{
	private:
		std::vector<shared<Component>> m_components;
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
			rtn->postInitialize(rtn, m_self.lock());

			m_components.push_back(rtn);
			return rtn;
		}

		void deleteComponent(shared<Component> _component);
		shared<Core> getCore();
		shared<Transform> getTransform();
		std::vector<shared<Component>> getComponents();

		template <typename T>
		std::vector<shared<T>> getComponent()
		{
			std::vector<shared<T>> rtn;
			for (shared<Component> component : m_components)
			{
				shared<T> Tcomp = std::dynamic_pointer_cast<T>(component);
				if (Tcomp)
				{
					rtn.push_back(Tcomp);
				}
			}

			return rtn;
		}

		void update();
		void render(glm::mat4 _viewMatrix, glm::mat4 _projMatrix);

	};

}