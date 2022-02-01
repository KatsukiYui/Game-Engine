#include "MemoryDefines.h"
#include <vector>
#include <SDL.h>
#include <glew.h>

namespace myengine
{
	//forward declaring entity since its used as a pointer
	class Entity;
	class Timer;
	class AssetManager;
	class Core
	{
	private:
		//add a contructor
		std::vector<shared<Entity> > m_entities;
		weak<Core> m_self;
		shared<AssetManager> m_assetManager;
		shared<SDL_Window*> m_window;
		shared<Timer> m_timer;
		bool m_stop = false;

	public:
		static shared<Core> initialize();
		void start();
		shared<Entity> addEntity();
		void deleteEntity(shared<Entity> _entity);

		shared<AssetManager> getAssetManager();
	};

}