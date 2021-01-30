#pragma once
#include "ManagerOfManagers.h"
#include "SaveSystem.h"
#include <iostream>

class Thing : public GameObject
{
	public:

	float speed;
	Thing(Vector2 position, string spritePath, float speed):GameObject()
	{
		transform.position = position;
		this->speed = speed;
		addSprite(spritePath, 1);
		addCollider(10);
	}
	
	void update() override
	{
		translate(Vector2::RIGHT * speed * InputManager::GetInstance().GetAxis("Horizontal Arrows"));
	}
};

int main(int argc, char* args[])
{
	ManagerOfManagers::CreateSingleton();

	// Start up SDL and create window
	if (!ManagerOfManagers::GetInstance().Init(1280, 720))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		RenderManager::GetInstance().HideCursor();
		// GameObject instances

		Thing thing (Vector2(RenderManager::GetInstance().SCREEN_WIDTH * 0.5, RenderManager::GetInstance().SCREEN_HEIGHT * 0.5),
			"../../Media/Sprites/Pong/ball.png", 50);


		// While application is running
		while (ManagerOfManagers::GetInstance().gameRunning)
		{
			// Update all managers and scripts
			ManagerOfManagers::GetInstance().Update();
		}
	}

	// Free memory and close program
	ManagerOfManagers::GetInstance().Destroy();
}

//Viva CSHARP