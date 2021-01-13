#pragma once
#include "ManagerOfManagers.h"
#include "Leaf.h"
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
		SaveSystem saveSytem;
		
		HUDElement score = HUDElement(RenderManager::GetInstance().SCREEN_WIDTH * 0.5, 10, "0");
	public:
		LeafManager();
		void update() override;
		void newLeaf();
		void addPoint();
};
