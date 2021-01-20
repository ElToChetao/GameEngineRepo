#pragma once
#include "Singleton.h"
#include "SDL.h"
#include "Vector2.h"
#include "GameObject.h"
#include "Manager.h"
#include <Texture.h>
#include <vector>


class GameObjectManager:public Singleton<GameObjectManager>
{
private:
	friend class Singleton<GameObjectManager>;
	vector<GameObject*> gameObjects;
	vector<Manager*> managers;
	vector<GameObject*> destroy;

	GameObjectManager();
	~GameObjectManager();
	
public:
	vector<GameObject*> GetGameObjects();

	void Init();
	
	void Update();

	void AddGameObject(GameObject* go);
	void RemoveGameObject(GameObject* go);
	void AddManager(Manager* go);
	void RemoveManager(Manager* go);

	Manager* GetManager(string name);

	GameObject* Find(string name);
};

