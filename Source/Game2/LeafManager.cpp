#include "LeafManager.h"

LeafManager::LeafManager()
{
	this->name = "LeafManager";
	this->points = 0;
	this->leavesOnScreen = 0;
	this->newLeafCounter = 1.5;
	this->amountOfLeaves = 5;
	this->currentLeafCounter = 0;
}

void LeafManager::update()
{
	currentLeafCounter += TimeManager::GetInstance().getDeltaTime();

	if (currentLeafCounter >= newLeafCounter)
	{
		for (int i = 0; i < amountOfLeaves; i++)
		{
			newLeaf();
		}
		currentLeafCounter = 0;
	}

}

void LeafManager::newLeaf()
{
	float x = 0.1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0.9 - 0.1)));
	float y = 0.1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0.9 - 0.1)));

	Vector2 si = RenderManager::GetInstance().GetScreenAdaptedPosition(x, y);

	Leaf* p = new Leaf (si);

	leavesOnScreen++;
}

void LeafManager::addPoint()
{
	points++;
	leavesOnScreen--;
	score.UpdateContent(to_string(points));
}