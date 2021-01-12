#pragma once
#include "ManagerOfManagers.h"
#include "Leaf.h"
using namespace std;

class LeafManager : public Manager
{
	private:
		int points;
		int leavesOnScreen;
		int amountOfLeaves;
		float newLeafCounter;
		float currentLeafCounter;
		
		HUDElement score = HUDElement(5, 5, "0");
	public:
		LeafManager();
		void update() override;
		void newLeaf();
		void addPoint();
};
