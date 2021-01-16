#include "LeafManager.h"
LeafManager::LeafManager()
{
	this->name = "LeafManager";
	this->points = 0;
	this->leavesOnScreen = 0;
	this->newLeafCounter = 3;
	this->amountOfLeaves = 5;
	this->currentLeafCounter = 0;
	this->fuelCounter = 7;
	this->currentFuelCounter = 0;

	button->addText("PLAY");
}

void LeafManager::update()
{
	//if (InputManager::GetInstance().GetKey())
	if (button != NULL && button->MouseOverButton())
	{
		gameStarted = true;
		delete button;
	}

	if (gameStarted) 
	{
		float dt = TimeManager::GetInstance().getDeltaTime();
		currentLeafCounter += dt;
		currentFuelCounter += dt;

		if (currentLeafCounter >= newLeafCounter)
		{
			for (int i = 0; i < amountOfLeaves; i++)
			{
				newLeaf();
			}

			amountOfLeaves = rand() % 10 + 5;

			currentLeafCounter = 0;
		}
		if (currentFuelCounter >= fuelCounter)
		{
			newFuel();
			currentFuelCounter = 0;
		}
	}
}

void LeafManager::newFuel()
{
	float x = 0.1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0.9 - 0.1)));
	float y = 0.1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0.9 - 0.1)));

	Vector2 startPosition = RenderManager::GetInstance().GetScreenAdaptedPosition(x, y);

	Fuel* f = new Fuel(startPosition);
}

void LeafManager::newLeaf()
{
	float x = 0.1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0.9 - 0.1)));
	float y = 0.1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0.9 - 0.1)));

	Vector2 startPosition = RenderManager::GetInstance().GetScreenAdaptedPosition(x, y);

	Leaf* p = new Leaf (startPosition);

	leavesOnScreen++;
}

void LeafManager::addPoint()
{
	points++;
	leavesOnScreen--;
	score.UpdateContent(to_string(points));
}