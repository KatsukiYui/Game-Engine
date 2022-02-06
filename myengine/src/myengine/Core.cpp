#include "Core.h"
#include "Entity.h"
#include "Camera.h"
#include "Transform.h"
#include "Input.h"
#include "Timer.h"
#include "Debugger.h"
#include "Exception.h"
#include "AssetManager.h"
#include "PhysicsManager.h"
#include "InputManager.h"
#include "AudioListener.h"
#include "AudioSource.h"

namespace myengine
{
	shared<Core> Core::initialize()
	{
		shared<Core> rtn = std::make_shared<Core>();
		rtn->m_self = rtn;

		try
		{
			if (SDL_Init(SDL_INIT_VIDEO) < 0)
			{
				throw Exception("SDL NOT INITIALIZED");
			}

			rtn->m_window = std::make_shared<SDL_Window*>(SDL_CreateWindow("Life is Pain",
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				rtn->m_windowSize.x, rtn->m_windowSize.y,
				SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL));

			if (!SDL_GL_CreateContext(*(rtn->m_window)))
			{
				throw Exception("SDL WINDOW BROKEN");
			}
			if (glewInit() != GLEW_OK)
			{
				throw Exception("GLEW NOT INITIALIZED");
			}

			// Initialize OpenAL
			rtn->m_audioDevice = std::make_shared<ALCdevice*>();
			*(rtn->m_audioDevice) = alcOpenDevice(NULL);

			if (!*(rtn->m_audioDevice))
			{
				throw Exception("AUDIO DEVICE NOT FOUND");
			}
			else
			{
				rtn->m_audioContext = std::make_shared<ALCcontext*>();
				*(rtn->m_audioContext) = alcCreateContext(*(rtn->m_audioDevice), NULL);

				if (!*(rtn->m_audioContext))
				{
					alcCloseDevice(*(rtn->m_audioDevice));

					throw Exception("AUDIO CONTEXT NOT FOUND");
				}
				else
				{
					if (!alcMakeContextCurrent(*(rtn->m_audioContext)))
					{
						alcDestroyContext(*(rtn->m_audioContext));
						alcCloseDevice(*(rtn->m_audioDevice));

						throw Exception("AUDIO CONTEXT NOT INITIALIZED");

					}
				}
			}

			rtn->m_assetManager = std::make_shared<AssetManager>();
			rtn->m_assetManager->initialize(rtn->m_assetManager, rtn);

			rtn->m_physicsManager = std::make_shared<PhysicsManager>();
			rtn->m_physicsManager->initialize(rtn->m_physicsManager, rtn);

			rtn->m_inputManager = std::make_shared<InputManager>();
		}
		catch (Exception e)
		{
			Debugger::printError(e.get());
		}

		return rtn;
	}

	void Core::start()
	{
		while (!m_stop)
		{
			// check frame input
			m_inputManager->update();

			// Update world
			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				m_entities.at(ei)->update();
			}

			// Draw our world
			// Specify the colour to clear the framebuffer to
			glClearColor(0.95f, 0.7f, 0.7f, 1.0f);
			// This writes the above colour to the colour part of the framebuffer
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// Render world    
			SDL_GetWindowSize(*m_window, &m_windowSize.x, &m_windowSize.y);

			if (m_cameras.size() > 0)
			{
				shared<Camera> camera = m_cameras[0];
				if (camera)
				{
					glm::mat4 viewingMatrix = camera->getTransform()->getModelMatrix();
					glm::mat4 projectionMatrix = camera->getProjectionMatrix(m_windowSize.x, m_windowSize.y);

					for (size_t ei = 0; ei < m_entities.size(); ++ei)
					{
						m_entities.at(ei)->render(viewingMatrix, projectionMatrix);
					}
				}
			}
			else
			{
				Debugger::printWarning("ADD CAMERA IDIOT!!!!!");
			}

			// This tells the renderer to actually show its contents to the screen
			// We'll get into this sort of thing at a later date - or just look up 'double buffering' if you're impatient :P
			SDL_GL_SwapWindow(*m_window);	

			if (m_inputManager->getInput()->quit() || m_inputManager->getInput()->isKeyDown(ESCAPE))
			{
				m_stop = true;
			}
		}
	}

	shared<Entity> Core::addEntity()
	{
        shared<Entity> rtn = std::make_shared<Entity>();
		rtn->initialize(rtn, m_self.lock());

		m_entities.push_back(rtn);
		Debugger::printLog("Entity Added yaaay!");
		return rtn;
	}

	void Core::deleteEntity(shared<Entity> _entity)
	{
		std::vector<shared<Entity>>::iterator it;
		it = std::find(m_entities.begin(), m_entities.end(), _entity);

		if (it != m_entities.end())
		{
			// delete entity components first
			std::vector<shared<Component>> components = _entity->getComponents();
			for (shared<Component> component : components)
			{
				_entity->deleteComponent(component);
			}

			m_entities.erase(it);
		}
		else
		{
			Debugger::printError("Entity Not Found");
		}
	}

	void Core::addCamera(shared<Camera> _camera)
	{
		m_cameras.push_back(_camera);
	}

	void Core::deleteCamera(shared<Camera> _camera)
	{
		std::vector<shared<Camera>>::iterator it;
		it = std::find(m_cameras.begin(), m_cameras.end(), _camera);

		if (it != m_cameras.end())
		{
			m_cameras.erase(it);
		}
		else
		{
			Debugger::printError("Camera Not Found");
		}
	}

	shared<AssetManager> Core::getAssetManager()
	{
		return m_assetManager;
	}

	shared<PhysicsManager> Core::getPhysicsManager()
	{
		return m_physicsManager;
	}

	shared<InputManager> Core::getInputManager()
	{
		return m_inputManager;
	}

	Core::~Core()
	{
		// OpenAL
		alcMakeContextCurrent(NULL);
		alcDestroyContext(*m_audioContext);
		alcCloseDevice(*m_audioDevice);

		//SDL
		SDL_DestroyWindow(*m_window);
		SDL_Quit();
	}
}