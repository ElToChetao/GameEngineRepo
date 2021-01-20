#pragma once
#include "ManagerOfManagers.h"
#include "SaveSystem.h"
#include "PoolManager.h"
#include "Car.h"
#include "Leaf.h"
#include "LeafManager.h"
#include "Button.h"
#include "SaveSystem.h"
//#incldue "PowerUp.h"
#include <iostream>

int main( int argc, char* args[] )
{
	ManagerOfManagers::CreateSingleton();

	// Start up SDL and create window
	if(!ManagerOfManagers::GetInstance().Init(1280, 720))
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		RenderManager::GetInstance().HideCursor();
		// GameObject instances
		LeafManager leafManager;
		Car car;

		AudioManager::GetInstance().PlaySound("../../Media/Sounds/music.wav", 20);
		RenderManager::GetInstance().SetBackgroundColor(42, 212, 83);

		string s = "numero";
		int num = 10;
		SaveSystem::Save<int>(num, s);
		bool b = SaveSystem::SaveExists("hola");
		cout << b;
		
		// While application is running
		while( ManagerOfManagers::GetInstance().gameRunning)
		{
			// Update all managers and scripts
			ManagerOfManagers::GetInstance().Update();
		}
	}

	// Free memory and close program
	ManagerOfManagers::GetInstance().Destroy();
}