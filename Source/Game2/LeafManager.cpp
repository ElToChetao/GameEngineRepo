#include "LeafManager.h"

LeafManager::LeafManager()
{
	this->name = "LeafManager";
	this->points = 0;
	this->leavesOnScreen = 0;
	this->newLeafCounter = 3;
	this->amountOfLeaves = 5;
	this->currentLeafCounter = 0;
	this->fuelCounter = 10;
	this->currentFuelCounter = 0;
	this->isEndGame = false;
	

	if (SaveSystem::SaveExists("Score"))
	{
		this->highScore = SaveSystem::Load<int>("Score");
		this->highScoreText.UpdateContent("HIGHSCORE: " + to_string(this->highScore));
	}
		
	RenderManager::GetInstance().SetBackgroundColor(42, 212, 83);

	button->addText("PLAY");
}

LeafManager::~LeafManager()
{
	if(points > highScore)
		SaveSystem::Save(points, "Score");
}

void LeafManager::update()
{
	if (button->isActive && button->Pressed())
	{
		points = 0;
		gameStarted = true;
		button->isActive = false;
		endScore.UpdateContent(" ");
		AudioManager::GetInstance().PlaySound("../../Media/Sounds/music.wav", 20);
	}
	if (gameStarted) 
	{
		float dt = TimeManager::GetInstance().getDeltaTime();
		currentLeafCounter += dt;
		currentFuelCounter += dt;

		if (currentLeafCounter > newLeafCounter)
		{
			for (int i = 0; i < amountOfLeaves; i++)
			{
				newLeaf();
			}

			amountOfLeaves = rand() % 3 + 5;

			currentLeafCounter = 0;
		}
		if (currentFuelCounter > fuelCounter)
		{
			newFuel();
			fuelCounter = 10 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (20 - 10)));
			currentFuelCounter = 0;
		}
	}
}

void LeafManager::newFuel()
{
	double x = 0.1 + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (0.9 - 0.1)));
	double y = 0.1 + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (0.9 - 0.1)));

	Vector2 startPosition = RenderManager::GetInstance().GetScreenAdaptedPosition(x, y);

	Fuel* f = new Fuel(startPosition);
}

void LeafManager::newLeaf()
{
	float x = 0.1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0.9 - 0.1)));
	float y = 0.1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0.9 - 0.1)));

	Vector2 startPosition = RenderManager::GetInstance().GetScreenAdaptedPosition(x, y);

	Leaf* p = new Leaf(startPosition);
	numSpawn++;
	leavesOnScreen++;
}

void LeafManager::addPoint()
{
	points++;
	leavesOnScreen--;
	score.UpdateContent(to_string(points));
}

void LeafManager::endGame()
{
	gameStarted = false;
	endScore.UpdateContent("FINAL SCORE: " + to_string(points));

	if (points > highScore)
	{
		SaveSystem::Save(points, "Score");
		highScore = points;
		highScoreText.UpdateContent("HIGHSCORE: " + to_string(points));
	}
		
	button->isActive = true;
	currentLeafCounter = 0;
	currentFuelCounter = 0;
	points = 0;
}

bool LeafManager::isGameStarted()
{
	return gameStarted;
}
