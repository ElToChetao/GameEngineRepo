#pragma once
#include "ManagerOfManagers.h"
#include "LeafManager.h"
using namespace std;

class Leaf:public GameObject
{
	private:
		Vector2 startPosition;

	public:
		Vector2 direction;
		float currentSpeed;

		Leaf(Vector2 startingPosition);
		void update() override;

		void addForce(Vector2 direction, float magnitude);
		void leafMovement(float dt);
};