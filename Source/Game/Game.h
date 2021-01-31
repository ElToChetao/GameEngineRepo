#pragma once
#include "ManagerOfManagers.h"
#include "SaveSystem.h"
#include "PoolManager.h"
#include "Paddle.h";
#include "Ball.h"

class Game {
public :
	Game() {
		ManagerOfManagers::CreateSingleton();

		//Start up SDL and create window
		if (!ManagerOfManagers::GetInstance().Init(800, 600))
		{
			printf("Failed to initialize!\n");
		}
		else
		{
			// GameObject instances

			Paddle leftPaddle(Vector2(30, RenderManager::GetInstance().SCREEN_HEIGHT / 2), "../../Media/Sprites/Pong/paddleLeft.png", "Vertical", Vector2(50, 20));
			leftPaddle.name = "leftPaddle";
			Paddle rightPaddle(Vector2(RenderManager::GetInstance().SCREEN_WIDTH - 60,
				RenderManager::GetInstance().SCREEN_HEIGHT / 2), "../../Media/Sprites/Pong/paddleRight.png", "Vertical Arrows", Vector2(RenderManager::GetInstance().SCREEN_WIDTH - 60, 20));
			rightPaddle.name = "rightPaddle";

			Ball ball;

			RenderManager::GetInstance().SetBackgroundColor(133, 133, 133);

			//While application is running
			while (ManagerOfManagers::GetInstance().gameRunning)
			{
				// update all managers and scripts
				ManagerOfManagers::GetInstance().Update();
			}
		}

		// Free memory and close program
		ManagerOfManagers::GetInstance().Destroy();
	}
};