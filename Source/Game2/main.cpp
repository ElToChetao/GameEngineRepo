#pragma once
#include "ManagerOfManagers.h"
#include "SaveSystem.h"
#include "PoolManager.h"
#include "Car.h"
#include "Leaf.h"
#include "LeafManager.h"
//#incldue "PowerUp.h"

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
		Car car;
		LeafManager leafManager;

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