#include "GameObjectManager.h"

GameObjectManager::GameObjectManager() {}

GameObjectManager::~GameObjectManager()
{
	/*for (int i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}

	for (int i = 0; i < managers.size(); i++)
	{
		delete managers[i];
	}*/

	managers.clear();
	gameObjects.clear();
}

vector<GameObject*> GameObjectManager::GetGameObjects() {
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

	for (int i = gameObjects.size()-1; i >= 0 ; i--) {
		if (gameObjects[i] != NULL || gameObjects[i] != nullptr && gameObjects[i]->isActive)
		{
			gameObjects[i]->update();
		}
	}
}

void GameObjectManager::Destroy() {

}

void GameObjectManager::AddGameObject(GameObject* go) {
	gameObjects.push_back(go);
}

void GameObjectManager::RemoveGameObject(GameObject* go) {
	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i] == go)
		{
			delete gameObjects[i];
			gameObjects.erase(gameObjects.begin() + i);
		}
	}
}

void GameObjectManager::AddManager(Manager* go) {
	managers.push_back(go);
}

void GameObjectManager::RemoveManager(Manager* go) {

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
