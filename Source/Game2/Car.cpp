#pragma once
#include "Car.h"

Car::Car():GameObject()
{
	transform.position = RenderManager::GetInstance().GetScreenAdaptedPosition(0.5, 0.5);
	transform.size = Vector2(83,128);
	maxFuel = 1;
	currentFuel = maxFuel;

	addSprite("../../Media/Sprites/CarLeaf/car.png");
	addCollider();
}

void Car::update()
{
	updatePosition();
}

void Car::updatePosition()
{
	transform.position = InputManager::GetInstance().GetMousePosition();
	transform.position.x -= (transform.size.x / 2);
	transform.position.y -= (transform.size.y / 2);
}

void Car::onCollisionEnter(GameObject* obj)
{
	if (Leaf* p = dynamic_cast<Leaf*>(obj))
	{
		Vector2 direction = transform.position.direction(p->transform.position);
		p->addForce(direction.normalize(), 500);
	}
	//Fuel
	/*else if (Leaf* p = dynamic_cast<Leaf*>(obj))
	{
		currentFuel++
	}*/
}