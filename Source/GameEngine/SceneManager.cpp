#include "SceneManager.h"
#include "GameObjectManager.h"
#include "RenderManager.h"

SceneManager::SceneManager()
{
	nextSceneIndex = 0;
	sceneIndex = 0;
}

void SceneManager::Init()
{

}

void SceneManager::Update(void)
{
	if (nextSceneIndex != sceneIndex) 
	{
		sceneIndex = nextSceneIndex;

		LoadScene();
	}
}

void SceneManager::LoadScene() 
{
	GameObjectManager::GetInstance().SetGameObjects(GetCurrentScene()->GetGameObjects());
	GameObjectManager::GetInstance().SetManagers(GetCurrentScene()->GetManagers());
	RenderManager::GetInstance().SetHUDElements(GetCurrentScene()->GetHUDElements());
}

void SceneManager::Destroy(void)
{

}

void SceneManager::AddScene(Scene* scene)
{
	scenes.push_back(scene);
}

Scene* SceneManager::GetScene(int index)
{
	if (index < scenes.size())
	{
		return scenes[index];
	}
	return nullptr;
}

Scene* SceneManager::GetCurrentScene()
{
	return scenes[sceneIndex];
}

void SceneManager::LoadScene(int index)
{
	nextSceneIndex = index;
}

void SceneManager::NextScene()
{
	nextSceneIndex++;
}
