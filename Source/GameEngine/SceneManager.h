#pragma once
#include "Singleton.h"
#include "Scene.h"
class SceneManager :public Singleton<SceneManager>
{
private:
	vector<Scene*> scenes;
	friend class Singleton<SceneManager>;
	int sceneIndex;
	int nextSceneIndex;

public:
	SceneManager();

	void Init();
	void Update(void);

	void Destroy(void);
	void AddScene(Scene* scene);

	Scene* GetScene(int index);
	Scene* GetCurrentScene();

	void LoadScene();
	void LoadScene(int index);
	void NextScene();
};