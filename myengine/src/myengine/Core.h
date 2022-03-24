#include "MemoryDefines.h"
#include <vector>
#include <SDL.h>
#include <glm/glm.hpp>
#include <glew.h>
#include <al.h>
#include <alc.h>

namespace myengine
{
	//forward declaring entity since its used as a pointer
	class Entity;
	class Timer;
	class AssetManager;
	class PhysicsManager;
	class InputManager;
	class Camera;
	class AudioListener;

	class Core
	{
	private:
		glm::ivec2 m_windowSize{ 800, 600 };
		std::vector<shared<Entity>> m_entities;
		std::vector<shared<Camera>> m_cameras;
		weak<Core> m_self;
		shared<AssetManager> m_assetManager;
		shared<PhysicsManager> m_physicsManager;
		shared<InputManager> m_inputManager;
		shared<SDL_Window*> m_window;
		shared<ALCdevice*> m_audioDevice;
		shared<ALCcontext*> m_audioContext;
		shared<Timer> m_timer;
		bool m_stop = false;

	public:
		~Core();
		static shared<Core> initialize();
		void start();
		shared<Entity> addEntity();
		void deleteEntity(shared<Entity> _entity);

		void addCamera(shared<Camera> _camera);
		void deleteCamera(shared<Camera> _camera);

		shared<AssetManager> getAssetManager();
		shared<PhysicsManager> getPhysicsManager();
		shared<InputManager> getInputManager();
		float getDeltaTime();
	};

}