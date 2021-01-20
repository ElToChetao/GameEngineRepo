#include "Scene.h"
#include "SceneManager.h"
Scene::Scene() 
{
	SceneManager::GetInstance().AddScene(this);
}
void Scene::AddGameobject(GameObject* go)
{
}

void Scene::AddManager(Manager* manager)
{
	sceneManagers.push_back(manager);
}

void Scene::AddHUDElement(HUDElement* go)
{
}
