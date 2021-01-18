#pragma once
#include "GameObject.h"
#include "HUDElement.h"
class Scene
{
private:
	vector<GameObject*> sceneObjects;
	vector<HUDElement*> hudElements;
public:
	Scene() {};

	void AddGameobject(GameObject* go);
	void AddHUDElement(HUDElement* go);
};

