#include "Core.h"
#include "Entity.h"
#include "Timer.h"
#include "Debugger.h"
#include "Exception.h"
#include "AssetManager.h"

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
				800, 600,
				SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL));

			if (!SDL_GL_CreateContext(*(rtn->m_window)))
			{
				throw Exception("SDL WINDOW BROKEN");
			}
			if (glewInit() != GLEW_OK)
			{
				throw Exception("GLEW NOT INITIALIZED");
			}

			rtn->m_assetManager = std::make_shared<AssetManager>();
			rtn->m_assetManager->initialize(rtn->m_assetManager, rtn);

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
			// Update world    //change this to iterator
			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				m_entities.at(ei)->update();
			}
			// Render world    
			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				//m_entities.at(ei)->render();
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
			m_entities.erase(it);
		}
		else
		{
			Debugger::printError("Entity Not Found");
		}
	}

}