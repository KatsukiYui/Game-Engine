namespace myengine
{
	struct Component;
	struct Core;

	class Entity
	{
	public:
		static shared<Entity> initialize(shared<Core> _core);
		shared<Entity> addComponent();
		shared<Core> getCore();

	private:
		//add a contructor
		std::vector<shared<Component> > components;
		weak<Core> core;
		weak<Entity> self;
	};

}