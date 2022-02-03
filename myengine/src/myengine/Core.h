#include "MemoryDefines.h"
#include <vector>
#include <SDL.h>
#include <glm/glm.hpp>
#include <glew.h>

namespace myengine
{
	//forward declaring entity since its used as a pointer
	class Entity;
	class Timer;
	class AssetManager;
	class Camera;

	class Core
	{
	protected:
		glm::ivec2 m_windowSize{ 800, 600 };
		std::vector<shared<Entity>> m_entities;
		std::vector<shared<Camera>> m_cameras;
		weak<Core> m_self;
		shared<AssetManager> m_assetManager;
		shared<SDL_Window*> m_window;
		shared<Timer> m_timer;
		bool m_stop = false;

	public:
		~Core();
		static shared<Core> initialize();
		void start();
		shared<Entity> addEntity();
		void deleteEntity(shared<Entity> _entity);

		void addCamera(shared<Camera> _camera);
		shared<AssetManager> getAssetManager();
	};

}