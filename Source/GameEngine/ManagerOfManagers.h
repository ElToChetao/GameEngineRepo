#pragma once
#include "Singleton.h"
#include "SDL.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "GameObjectManager.h"
#include "PhysicsManager.h"
#include "TimeManager.h"
#include "AudioManager.h"
#include <thread>         // std::thread
#include <mutex>          // std::mutex

class ManagerOfManagers :public Singleton<ManagerOfManagers>
{
	friend class Singleton<ManagerOfManagers>;
	std::mutex mut;
public:
	bool gameRunning;
	ManagerOfManagers();

	bool Init(int w, int h);

	void GraphicThread();
	void Update(void);
	
	void Exit();

	void Destroy(void);
};
