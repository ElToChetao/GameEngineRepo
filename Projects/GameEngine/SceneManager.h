#pragma once
#include "Singleton.h"

class SceneManager :public Singleton<SceneManager>
{
	friend class Singleton<SceneManager>;
public:
	SceneManager();

	void Init();
	void Update(void);

	void Destroy(void);
};