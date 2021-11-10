#pragma once

#include <memory>
#include <vector>
#include <SDL.h>
#include <glew.h>

namespace myengine
{

#define shared std::shared_ptr
#define weak std::weak_ptr

	//forward declaring entity since its used as a pointer
	class Entity;

	class Core
	{
	public:
		static shared<Core> initialize();
		void start();
		shared<Entity> addEntity();

	private:
		//add a contructor
		std::vector<shared<Entity> > m_entities;
		weak<Core> m_self;
		shared<SDL_Window*> m_window;
		bool m_stop = false;
	};

}