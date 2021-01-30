#include "ManagerOfManagers.h"
#include <chrono>

ManagerOfManagers::ManagerOfManagers() {
	gameRunning = true;
}

bool ManagerOfManagers::Init(int w, int h) {
	
	// init all managers
	TimeManager::CreateSingleton();
	InputManager::CreateSingleton();
	GameObjectManager::CreateSingleton();
	RenderManager::CreateSingleton();
	PhysicsManager::CreateSingleton();
	AudioManager::CreateSingleton();
	GameObjectManager::GetInstance().Init();


	RenderManager::CreateSingleton();

	AudioManager::GetInstance().Init();
	if (!RenderManager::GetInstance().Init(w, h))
	{
		return false;
	}
	return true;
}

void ManagerOfManagers::Update(void) {

	std::thread renderThread(&ManagerOfManagers::GraphicThread, &ManagerOfManagers::GetInstance());

	while (gameRunning)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				Exit();
			}
		}

		// update all managers
		TimeManager::GetInstance().Update();
		InputManager::GetInstance().Update();
		PhysicsManager::GetInstance().Update();

		if (mut.try_lock()) {
			GameObjectManager::GetInstance().Update();

			mut.unlock();
		}
		printf("\nFin del obj");

		AudioManager::GetInstance().Update();

		printf("\nFin del main");

	}
	renderThread.join();
}
void ManagerOfManagers::GraphicThread()
{
	while (gameRunning)
	{
		if (mut.try_lock()) {
			RenderManager::GetInstance().Update();

			mut.unlock();
			std::chrono::milliseconds timespan(17); // or whatever
			std::this_thread::sleep_for(timespan);

			printf("\n Fin del Render");
		}
	}

	RenderManager::DestroySingleton();
}

void ManagerOfManagers::Exit()
{
	gameRunning = false;
}

void ManagerOfManagers::Destroy(void) 
{
	AudioManager::DestroySingleton();

	GameObjectManager::DestroySingleton();
	PhysicsManager::DestroySingleton();
	InputManager::DestroySingleton();
	TimeManager::DestroySingleton();
	ManagerOfManagers::DestroySingleton();

	SDL_Quit();
	exit(0);
}