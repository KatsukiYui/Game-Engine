#include <memory>
#include <vector>

#define shared std::shared_ptr
#define weak std::weak_ptr

namespace myengine
{
	//forward declaring entity since its used as a pointer
	class Entity;

	//maybe change this into a class? why is it a struct
	class Core
	{		
	public:
		static shared<Core> initialize();
		void start();
		shared<Entity> addEntity();

	private:
		//add a contructor
		//int dummy;
		std::vector<shared<Entity> > entities;
		weak<Core> self;
	};