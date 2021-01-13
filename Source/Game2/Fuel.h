#pragma once
#include "GameObject.h"
#include "Vector2.h"

using namespace std;

class Fuel :public GameObject
{
	public:
		Fuel(Vector2 startingPosition);
};