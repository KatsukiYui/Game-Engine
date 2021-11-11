#pragma once
#include "Core.h"

namespace myengine
{
	class Component;

	class Entity
	{
	public:
		shared<Entity> initialize(shared<Core> _core);
		shared<Component> addComponent();
		shared<Core> getCore();
		void update();

	private:
		//add a contructor
		std::vector<shared<Component> > m_components;
		weak<Core> m_core;
		weak<Entity> m_self;
	};

}