#pragma once
#include "GameObject.h"
#include "Manager.h"
#include "HUDElement.h"
class Scene
{
private:
	vector<GameObject*> sceneObjects;
	vector<Manager*> sceneManagers;
	vector<HUDElement*> hudElements;
public:
	Scene();

	void AddGameobject(GameObject* go);
	void AddManager(Manager* manager);
	void AddHUDElement(HUDElement* go);

	vector<GameObject*> GetGameObjects() { return sceneObjects; }
	vector<Manager*> GetManagers() { return sceneManagers; }
	vector<HUDElement*> GetHUDElements() { return hudElements; }
};

