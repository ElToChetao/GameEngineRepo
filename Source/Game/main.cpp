#pragma once
#include "ManagerOfManagers.h"
#include "SaveSystem.h"
#include "PoolManager.h"
#include "Paddle.h";
#include "Ball.h"

class Wall : public GameObject {
public:
	Wall(Vector2 startPos, Vector2 size) :GameObject() {
		transform.position.x = startPos.x;
		transform.position.y = startPos.y;
		transform.size.x = size.x;
		transform.size.y = size.y;

		addCollider();
	};
};

int main( int argc, char* args[] )
{
	ManagerOfManagers::CreateSingleton();

	//Start up SDL and create window
	if(!ManagerOfManagers::GetInstance().Init())
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		// GameObject instances

		Paddle leftPaddle(Vector2(30, RenderManager::GetInstance().SCREEN_HEIGHT / 2), "../../Media/Sprites/paddleLeft.png", "Vertical", Vector2(50, 20));
		leftPaddle.name = "leftPaddle";
		Paddle rightPaddle(Vector2(RenderManager::GetInstance().SCREEN_WIDTH - 60, 
			RenderManager::GetInstance().SCREEN_HEIGHT / 2), "../../Media/Sprites/paddleRight.png", "Vertical Arrows", Vector2(RenderManager::GetInstance().SCREEN_WIDTH - 60, 20));
		rightPaddle.name = "rightPaddle";

		Ball ball;

		//While application is running
		while( ManagerOfManagers::GetInstance().gameRunning )
		{
			// update all managers and scripts
			ManagerOfManagers::GetInstance().Update();
		}
	}

	// Free memory and close program
	ManagerOfManagers::GetInstance().Destroy();
}