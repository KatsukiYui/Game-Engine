#pragma once
#include "Core.h"

namespace myengine
{
	class Component;

	class Entity
	{
	public:
		shared<Entity> Initialize(shared<Core> _core);
		shared<Component> addComponent();
		shared<Core> getCore();

	private:
		//add a contructor
		std::vector<shared<Component> > Components;
		weak<Core> core;
		weak<Entity> self;
	};

}