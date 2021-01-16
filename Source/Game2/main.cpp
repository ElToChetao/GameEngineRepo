#pragma once
#include "ManagerOfManagers.h"
#include "SaveSystem.h"
#include "PoolManager.h"
#include "Car.h"
#include "Leaf.h"
#include "LeafManager.h"
#include "Button.h"
//#incldue "PowerUp.h"

int main( int argc, char* args[] )
{
	ManagerOfManagers::CreateSingleton();

	//Start up SDL and create window
	if(!ManagerOfManagers::GetInstance().Init(1280, 720))
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		RenderManager::GetInstance().HideCursor();
		// GameObject instances
		Car car;
		LeafManager leafManager;

		AudioManager::GetInstance().PlaySound("../../Media/Sounds/music.wav", 20);
		RenderManager::GetInstance().SetBackgroundColor(42, 212, 83);

		
		//While application is running
		while( ManagerOfManagers::GetInstance().gameRunning)
		{
			// update all managers and scripts
			ManagerOfManagers::GetInstance().Update();
		}
	}

	// Free memory and close program
	ManagerOfManagers::GetInstance().Destroy();
}