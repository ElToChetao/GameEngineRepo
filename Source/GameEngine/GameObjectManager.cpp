#include "GameObjectManager.h"

GameObjectManager::GameObjectManager() {}

GameObjectManager::~GameObjectManager()
{
	printf("si o q \n");
	for (int i = gameObjects.size()-1; i >= 0; i--)
	{
		printf("ee");
		delete gameObjects[i];
		printf("oo");
	}
	printf("SI");
	gameObjects.clear();

	printf("si o q \n");
	
	for (int i = managers.size()-1; i >= 0; i--)
	{
		delete managers[i];
	}

	printf("si o q \n");

	managers.clear();
}

vector<GameObject*> GameObjectManager::GetGameObjects()
{
	vector<GameObject*> activeObjects;

	for (int i = 0; i < gameObjects.size(); i++) {
		if (gameObjects[i]->isActive) {
			activeObjects.push_back(gameObjects[i]);
		}
	}
	return activeObjects;
}

void GameObjectManager::Init() {
}

void GameObjectManager::Update() 
{
	for (int i = managers.size()-1; i >= 0 ; i--) 
	{
		managers[i]->update();
	}

	for (int i = gameObjects.size()-1; i >= 0 ; i--) 
	{
		if (gameObjects[i] != NULL || gameObjects[i] != nullptr && gameObjects[i]->isActive)
		{
			gameObjects[i]->update();
		}
	}

	//Free
	for (int i = 0; i < destroy.size();	)
	{
		delete destroy[i];
		destroy.erase(destroy.begin() + i);
	}
}

void GameObjectManager::AddGameObject(GameObject* go) 
{
	gameObjects.push_back(go);
}

void GameObjectManager::RemoveGameObject(GameObject* go)
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i] == go)
		{
			destroy.push_back(gameObjects[i]);
			gameObjects.erase(gameObjects.begin() + i);
		}
	}
}

void GameObjectManager::AddManager(Manager* go) 
{
	managers.push_back(go);
}

void GameObjectManager::RemoveManager(Manager* go)
{

	for (int i = 0; i < managers.size(); i++)
	{
		if (managers[i] == go)
		{
			delete managers[i];
			managers.erase(managers.begin() + i);
		}
	}
}

Manager* GameObjectManager::GetManager(string name)
{
	for each (Manager* manager in managers)
	{
		if (manager->name._Equal(name)) {
			return manager;
		}
	}
	return nullptr;
}

GameObject* GameObjectManager::Find(string name)
{
	for each (GameObject* go in gameObjects)
	{
		if (go->name._Equal(name)) {
			return go;
		}
	}
	return nullptr;
}
