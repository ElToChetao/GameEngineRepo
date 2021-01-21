#include "ManagerOfManagers.h"

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
	AudioManager::GetInstance().Init();

	if (!RenderManager::GetInstance().Init(w, h))
	{
		return false;
	}
	return true;
}

void ManagerOfManagers::PhysicUpdate() {
	PhysicsManager::GetInstance().Update();
}
void ManagerOfManagers::InputUpdate() {
	TimeManager::GetInstance().Update();
	InputManager::GetInstance().Update();
}

void ManagerOfManagers::Update(void) {
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

	InputUpdate();
	PhysicUpdate();

	GameObjectManager::GetInstance().Update();
	RenderManager::GetInstance().Update();
	AudioManager::GetInstance().Update();
}

void ManagerOfManagers::Exit()
{
	gameRunning = false;
}
void ManagerOfManagers::Destroy(void) 
{
	AudioManager::DestroySingleton();
	RenderManager::DestroySingleton();
	GameObjectManager::DestroySingleton();
	PhysicsManager::DestroySingleton();
	InputManager::DestroySingleton();
	TimeManager::DestroySingleton();
	ManagerOfManagers::DestroySingleton();

	SDL_Quit();
	exit(0);
}