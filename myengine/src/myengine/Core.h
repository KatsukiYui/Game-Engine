#pragma once

#include "MemoryDefines.h"
#include <vector>
#include <SDL.h>
#include <glew.h>
#include "Timer.h"

namespace myengine
{
	//forward declaring entity since its used as a pointer
	class Entity;
	class Core
	{
	public:
		static shared<Core> initialize();
		void start();
		shared<Entity> addEntity();
		void deleteEntity(shared<Entity> _entity);

	private:
		//add a contructor
		std::vector<shared<Entity> > m_entities;
		weak<Core> m_self;
		shared<SDL_Window*> m_window;
		shared<Timer> m_timer;
		bool m_stop = false;
	};

}