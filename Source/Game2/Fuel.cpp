#include "Fuel.h"

Fuel::Fuel(Vector2 startingPosition):GameObject()
{
	transform.position = startingPosition;
	addSprite("../../Media/Sprites/CarLeaf/fuel.png", 1);
	addCollider(32);
}

Fuel::~Fuel()
{

}