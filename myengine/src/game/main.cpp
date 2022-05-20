#include "myengine/MyEngine.h"
#include "PlayerController.h"
#include "Cat.h"
#include "Enemy.h"
#include "Rotator.h"

#include <iostream>
#include <enet/enet.h>
#include <thread>
#include <chrono>

#include <nlohmann/json.hpp>

#define DELAY 100

using json = nlohmann::json;

static std::string IP = "localhost";

void initializeGame(shared<Core> _core);
shared<Transform> initializeGame2(shared<Core> _core);

void clientReceiveData(ENetHost* _client, shared<Transform> _transform);
void clientSendData(ENetPeer* _peer, shared<Transform> _transform);
int initializeServer();
int initializeClient(ENetPeer** _peer, ENetHost** _client);
void disconnectClient(ENetPeer* _peer, ENetHost* _client);

void startGame(shared<Core> _core);

void toJson(json& _j, const glm::vec3& _pos) {
	_j = json{ {"x", _pos.x}, {"y", _pos.y}, {"z", _pos.z} };
}

void fromJson(const json& _j, glm::vec3& _pos) {
	_j.at("x").get_to(_pos.x);
	_j.at("y").get_to(_pos.y);
	_j.at("z").get_to(_pos.z);
}

int main()
{
	#ifdef DEBUG
		std::cout << "Debug" << std::endl;
	#else
		std::cout << "Release" << std::endl;
	#endif // DEBUG

	Debugger::printLog("Enter 1(server) or 2(client)");
	int choice;
	std::cin >> choice;
	std::cout << std::endl << std::endl;

	if (choice == 1)
	{
		if (initializeServer() == EXIT_FAILURE)
		{
			Debugger::printError("Failed to initialize server");
		}
	}
	else if(choice == 2)
	{

		//set up client
		ENetPeer* peer;
		ENetHost* client;

		shared<Core> core = Core::initialize();

		// init game returns a pointer to player transform
		shared<Transform> playerTransform = initializeGame2(core);

		if (initializeClient(&peer, &client) == EXIT_FAILURE)
		{
			Debugger::printError("Failed to initialize client");

			return EXIT_FAILURE;
		}

		//threads for sending and receiving client data
		std::thread t1;
		std::thread t2;

		t1 = std::thread(clientSendData, peer, playerTransform);
		t2 = std::thread(clientReceiveData, client, playerTransform);
		startGame(core);

		if (t1.joinable()) { t1.join(); };
		if (t2.joinable()) { t2.join(); };

		//disconnect from server
		disconnectClient(peer, client);
	}
	else
	{
		Debugger::printError("Please choose 1 or 2");
	}


	return 0;
}

void initializeGame(shared<Core> _core)
{
	shared<Entity> player = _core->addEntity();
	shared<Camera> camera = player->addComponent<Camera>();
	shared<AudioListener> audioListener = player->addComponent<AudioListener>();
	shared<AudioSource> musicSource = player->addComponent<AudioSource>();
	musicSource->setAudio(_core->getAssetManager()->getAsset<Audio>("stardew.ogg"));
	musicSource->setLooping(true);
	musicSource->play(0.25f);
	player->getTransform()->setTransform(glm::vec3(0, 1.55, 2.5), glm::quat(1, 0, 0, 0), glm::vec3(1.0f, 1.0f, 1.0f));
	shared<PlayerController> playerController = player->addComponent<PlayerController>();


	shared<Entity> room = _core->addEntity();
	shared<MeshRenderer> roomMeshRenderer = room->addComponent<MeshRenderer>();
	roomMeshRenderer->setShader(_core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	roomMeshRenderer->setMesh(_core->getAssetManager()->getAsset<Mesh>("room.obj"));
	roomMeshRenderer->setTexture(_core->getAssetManager()->getAsset<Texture>("room.bmp"));
	room->getTransform()->setTransform(glm::vec3(0, 0, 0), glm::quat(glm::vec3(0, 0, 0)), glm::vec3(0.5f, 0.5f, 0.5f));



	shared<Entity> cat1 = _core->addEntity();
	shared<Rotator> rotator = cat1->addComponent<Rotator>();
	shared<MeshRenderer> meshRenderer1 = cat1->addComponent<MeshRenderer>();
	shared<SphereCollider> catCollider1 = cat1->addComponent<SphereCollider>();
	shared<Cat> catComponent1 = cat1->addComponent<Cat>();
	meshRenderer1->setShader(_core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	meshRenderer1->setMesh(_core->getAssetManager()->getAsset<Mesh>("cat.obj"));
	meshRenderer1->setTexture(_core->getAssetManager()->getAsset<Texture>("blackCat.bmp"));
	cat1->getTransform()->setTransform(glm::vec3(1, 0, 1.5), glm::quat(glm::vec3(0, 1.0f, 0)), glm::vec3(0.005f, 0.005f, 0.005f));

	shared<Entity> cat2 = _core->addEntity();
	shared<MeshRenderer> meshRenderer2 = cat2->addComponent<MeshRenderer>();
	shared<SphereCollider> catCollider2 = cat2->addComponent<SphereCollider>();
	shared<Cat> catComponent2 = cat2->addComponent<Cat>();
	meshRenderer2->setShader(_core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	meshRenderer2->setMesh(_core->getAssetManager()->getAsset<Mesh>("cat.obj"));
	meshRenderer2->setTexture(_core->getAssetManager()->getAsset<Texture>("pinkCat.bmp"));
	cat2->getTransform()->setTransform(glm::vec3(-1.2, 0, 1), glm::quat(glm::vec3(0, 1.2f, 0)), glm::vec3(0.005f, 0.005f, 0.005f));

	shared<Entity> cat3 = _core->addEntity();
	shared<MeshRenderer> meshRenderer3 = cat3->addComponent<MeshRenderer>();
	shared<SphereCollider> catCollider3 = cat3->addComponent<SphereCollider>();
	shared<Cat> catComponent3 = cat3->addComponent<Cat>();
	meshRenderer3->setShader(_core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	meshRenderer3->setMesh(_core->getAssetManager()->getAsset<Mesh>("cat.obj"));
	meshRenderer3->setTexture(_core->getAssetManager()->getAsset<Texture>("orangeCat.bmp"));
	cat3->getTransform()->setTransform(glm::vec3(0.8, 0, -1.2), glm::quat(glm::vec3(0, 0.5f, 0)), glm::vec3(0.005f, 0.005f, 0.005f));

	shared<Entity> cat4 = _core->addEntity();
	shared<MeshRenderer> meshRenderer4= cat4->addComponent<MeshRenderer>();
	shared<SphereCollider> catCollider4 = cat4->addComponent<SphereCollider>();
	shared<Cat> catComponent4 = cat4->addComponent<Cat>();
	meshRenderer4->setShader(_core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	meshRenderer4->setMesh(_core->getAssetManager()->getAsset<Mesh>("cat.obj"));
	meshRenderer4->setTexture(_core->getAssetManager()->getAsset<Texture>("crazyCat.bmp"));
	cat4->getTransform()->setTransform(glm::vec3(-1.7, 0, -1.1), glm::quat(glm::vec3(0, 0.2f, 0)), glm::vec3(0.005f, 0.005f, 0.005f));
}

shared<Transform> initializeGame2(shared<Core> _core)
{
	shared<Entity> player = _core->addEntity();
	shared<Camera> camera = player->addComponent<Camera>();
	shared<AudioListener> audioListener = player->addComponent<AudioListener>();
	shared<AudioSource> musicSource = player->addComponent<AudioSource>();
	musicSource->setAudio(_core->getAssetManager()->getAsset<Audio>("stardew.ogg"));
	musicSource->setLooping(true);
	musicSource->play(0.25f);
	player->getTransform()->setTransform(glm::vec3(0, 1.55, 2.5), glm::quat(1, 0, 0, 0), glm::vec3(1.0f, 1.0f, 1.0f));
	shared<PlayerController> playerController = player->addComponent<PlayerController>();


	shared<Entity> room = _core->addEntity();
	shared<MeshRenderer> roomMeshRenderer = room->addComponent<MeshRenderer>();
	roomMeshRenderer->setShader(_core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	roomMeshRenderer->setMesh(_core->getAssetManager()->getAsset<Mesh>("room.obj"));
	roomMeshRenderer->setTexture(_core->getAssetManager()->getAsset<Texture>("room.bmp"));
	room->getTransform()->setTransform(glm::vec3(0, 0, 0), glm::quat(glm::vec3(0, 0, 0)), glm::vec3(0.7f, 0.7f, 0.7f));

	//Enemies

	shared<Entity> target1 = _core->addEntity();
	shared<MeshRenderer> meshRenderer1 = target1->addComponent<MeshRenderer>();
	shared<SphereCollider> targetCollider1 = target1->addComponent<SphereCollider>();
	shared<Enemy> enemyComponent1 = target1->addComponent<Enemy>();
	meshRenderer1->setShader(_core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	meshRenderer1->setMesh(_core->getAssetManager()->getAsset<Mesh>("target.obj"));
	meshRenderer1->setTexture(_core->getAssetManager()->getAsset<Texture>("target.bmp"));
	target1->getTransform()->setTransform(glm::vec3(2, 2, 1), glm::quat(glm::vec3(0, 0, 0)), glm::vec3(0.01f, 0.01f, 0.01f));

	shared<Entity> target2 = _core->addEntity();
	shared<MeshRenderer> meshRenderer2 = target2->addComponent<MeshRenderer>();
	shared<SphereCollider> targetCollider2 = target2->addComponent<SphereCollider>();
	shared<Enemy> enemyComponent2 = target2->addComponent<Enemy>();
	meshRenderer2->setShader(_core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	meshRenderer2->setMesh(_core->getAssetManager()->getAsset<Mesh>("target.obj"));
	meshRenderer2->setTexture(_core->getAssetManager()->getAsset<Texture>("target.bmp"));
	target2->getTransform()->setTransform(glm::vec3(1, 1, 1), glm::quat(glm::vec3(0, 0, 0)), glm::vec3(0.01f, 0.01f, 0.01f));

	shared<Entity> target3 = _core->addEntity();
	shared<MeshRenderer> meshRenderer3 = target3->addComponent<MeshRenderer>();
	shared<SphereCollider> targetCollider3 = target3->addComponent<SphereCollider>();
	shared<Enemy> enemyComponent3 = target3->addComponent<Enemy>();
	meshRenderer3->setShader(_core->getAssetManager()->getAsset<ShaderProgram>("shaderProgram_Texture.txt"));
	meshRenderer3->setMesh(_core->getAssetManager()->getAsset<Mesh>("target.obj"));
	meshRenderer3->setTexture(_core->getAssetManager()->getAsset<Texture>("target.bmp"));
	target3->getTransform()->setTransform(glm::vec3(2, 1, 1), glm::quat(glm::vec3(0, 0, 0)), glm::vec3(0.01f, 0.01f, 0.01f));

	shared<Transform> rtn = player->getTransform();
	return rtn;
}

int initializeServer()
{
	//init enet
	if (enet_initialize() != 0)
	{
		std::cout << "failed to init enet" << std::endl;
		return EXIT_FAILURE;
	}

	//deinit at end of program
	atexit(enet_deinitialize);

	//Setup Server

	ENetHost* server;
	ENetAddress address;
	//ENetPeer* peer = NULL; //one client for now.. whoever connects first
	//where ever the server is running
	address.host = ENET_HOST_ANY;
	address.port = 4519;

	//address, amount of outgoing connections - how many peers are allowed to connect (0 if want variable)
	//, channels, incoming Bandwidth, Outgoing (0) means unlimited
	server = enet_host_create(&address, 3, 1, 0, 0);
	if (server == NULL)
	{
		std::cout << "failed to create a server" << std::endl;
		return EXIT_FAILURE;
	}

	ENetEvent event;

	bool first = true;
	enet_uint32 wait = 1000;

	//Game LOOP START
	while (true)
	{

		while (enet_host_service(server, &event, wait) > 0)
		{
			switch (event.type)
			{
			case ENET_EVENT_TYPE_CONNECT:
				std::cout << "A new client connected from " << event.peer->address.host << ":" << event.peer->address.port << std::endl;
				//peer = event.peer;
				wait = DELAY;
				break;
			case ENET_EVENT_TYPE_DISCONNECT:
				std::cout << event.peer->address.host << ":" << event.peer->address.port << " disconnected from the server." << std::endl;
				/* Reset the peer's client information. */
				event.peer->data = NULL;
				break;
			case ENET_EVENT_TYPE_RECEIVE:

				glm::vec3 pos;
				std::string message = (char*)(event.packet->data);
				json j = json::parse(message);
				fromJson(j, pos);

				std::cout << "CLIENT SENT: " << pos.x << " " << pos.y << " " << pos.z << std::endl;

				ENetPacket* packet = enet_packet_create(message.c_str(), strlen(message.c_str()) + 1, ENET_PACKET_FLAG_RELIABLE);
				// Lets broadcast this message to all
				enet_host_broadcast(server, 0, packet);

				/* Clean up the packet now that we're done using it. */
				enet_packet_destroy(event.packet);
				break;
			}
		}

	}
	//Game LOOP END

	enet_host_destroy(server);

}

int initializeClient(ENetPeer** _peer, ENetHost** _client)
{
	
	//init enet
	if (enet_initialize() != 0)
	{
		std::cout << "failed to init enet" << std::endl;
		return EXIT_FAILURE;
	}

	//deinit at end of program
	atexit(enet_deinitialize);

	//Setup client

	//ENetHost* client;
	//address (NULL for clients), amount of outgoing connections - only 1 server, channels, incoming Bandwidth, Outgoing (0) means unlimited
	*_client = enet_host_create(NULL, 1, 1, 0, 0);
	if (*_client == NULL)
	{
		std::cout << "failed to create a client" << std::endl;
		return EXIT_FAILURE;
	}

	bool first = true;
	enet_uint32 wait = 1000;

	ENetAddress serverAddress;
	ENetEvent event;
	//ENetPeer* peer; //for the server itll hold multiple for each client
	//Host IP
	enet_address_set_host(&serverAddress, IP.c_str());
	//enet_address_set_host(&serverAddress, "localhost");

	serverAddress.port = 4519;
	//channels, data
	*_peer = enet_host_connect(*_client, &serverAddress, 1, 0);

	if (_peer == NULL)
	{
		std::cout << "No available peers for initiating an ENet Connection" << std::endl;
		return EXIT_FAILURE;
	}

	//check if server sent data (last is ms time to wait)
	if (enet_host_service(*_client, &event, wait) > 0 && event.type == ENET_EVENT_TYPE_CONNECT)
	{
		std::cout << "Connection to server with IP " << IP << " Worked!" << std::endl;
	}
	else
	{
		enet_peer_reset(*_peer);
		std::cout << "Connection to server with IP " << IP << " Failed :(" << std::endl;
	}

	return 0;
}

void disconnectClient(ENetPeer* _peer, ENetHost* _client)
{
	//Disconnect from server
	ENetEvent event;
	enet_peer_disconnect(_peer, 0);
	//wait to hear from server
	while (enet_host_service(_client, &event, 3000) > 0)
	{
		switch (event.type)
		{
		case ENET_EVENT_TYPE_RECEIVE:
			//we trynna dc not receive data
			enet_packet_destroy(event.packet);
			break;
		case ENET_EVENT_TYPE_DISCONNECT:
			std::cout << "Disconnected from server!";
			break;
		}
	}
}

void startGame(shared<Core> _core)
{
	//start the engine/game loop
	_core->start();
}

//for the client to receive data (separate thread)
void clientReceiveData(ENetHost* _client, shared<Transform> _transform)
{

	ENetEvent event;

	while (true)
	{
		enet_uint32 wait = DELAY;

		while (enet_host_service(_client, &event, wait) > 0)
		{

			switch (event.type)
			{

			case ENET_EVENT_TYPE_RECEIVE:

				glm::vec3 position;
				std::string message = (char*)(event.packet->data);
				json j = json::parse(message);
				fromJson(j, position);

				//if (position != _transform->getPosition())
				{
					_transform->setPosition(position);
				}
				// Clean up the packet now that we're done using it.
				enet_packet_destroy(event.packet);

				break;
			}
		}
	}
}

void clientSendData(ENetPeer* _peer, shared<Transform> _transform)
{
	while (true)
	{
		glm::vec3 position = _transform->getPosition();
		json j;
		toJson(j, position);

		std::cout << "CLIENT SENDING: " << position.x << " " << position.y << " " << position.z << std::endl;

		std::string message = j.dump();

		//std::cout << "CLIENT SENDING: " << message << std::endl;

		ENetPacket* packet = enet_packet_create(message.c_str(), strlen(message.c_str()) + 1, ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(_peer, 0, packet);

	}
}
