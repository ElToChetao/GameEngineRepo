#pragma once
#include "ManagerOfManagers.h"
#include "Leaf.h"
#include "Fuel.h"
#include "SaveSystem.h"
#include "Text.h"
#include "Button.h"

using namespace std;

class LeafManager : public Manager
{
	private:
		int points;
		int highScore;
		int leavesOnScreen;
		int amountOfLeaves;

		float newLeafCounter;
		float currentLeafCounter;
		float fuelCounter;
		float currentFuelCounter;

		Button* button = new Button(Vector2(100, 100));

		bool gameStarted = false;

		Text score = Text(Vector2(RenderManager::GetInstance().SCREEN_WIDTH * 0.5, 10), "0");
		Text highScoreText = Text(Vector2(RenderManager::GetInstance().SCREEN_WIDTH * 0.8, 10), "HIGHSCORE: 0");

	public:
		LeafManager();
		~LeafManager();
		
		void update() override;

		void newLeaf();
		void newFuel();
		void addPoint();
};
