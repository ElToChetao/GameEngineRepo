#pragma once
#include "ManagerOfManagers.h"
#include "Leaf.h"
#include "Fuel.h"
#include "SaveSystem.h"

using namespace std;

class LeafManager : public Manager
{
	private:
		int points;
		int leavesOnScreen;
		int amountOfLeaves;

		float newLeafCounter;
		float currentLeafCounter;
		float fuelCounter;
		float currentFuelCounter;
		SaveSystem saveSytem;

		/*Lvl
		int leafLvl;
		int timeLeafSpwnLvl;
		int timefuelSpwnLvl;
		*/

		HUDElement score = HUDElement(RenderManager::GetInstance().SCREEN_WIDTH * 0.5, 10, "0");

	public:
		LeafManager();
		void update() override;

		void newLeaf();
		void newFuel();
		void addPoint();
};
