#include "Fuel.h"

Fuel::Fuel(Vector2 startingPosition)
{
	transform.position = startingPosition;
	addSprite("../../Media/Sprites/CarLeaf/fuel.png");
	addCollider(32);
}