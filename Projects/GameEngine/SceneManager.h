#pragma once
#include "Singleton.h"

class SceneManager :public Singleton<SceneManager>
{
	friend class Singleton<SceneManager>;
public:
	SceneManager();

	bool Init(int w, int h);
	void Update(void);

	void Destroy(void);
};