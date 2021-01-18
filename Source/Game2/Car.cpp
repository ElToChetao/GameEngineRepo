#pragma once
#include "Car.h"

Car::Car():GameObject()
{
	transform.position = InputManager::GetInstance().GetMousePosition();
	transform.size = Vector2(83,128);
	maxFuel = 1;
	currentFuel = maxFuel;
	currentForce = 0;
	maxForce = 10;

	addSprite("../../Media/Sprites/CarLeaf/car.png");
	addCollider();
}

void Car::update()
{
	float dt = TimeManager::GetInstance().getDeltaTime();
	updatePosition(dt);

	currentFuel -= dt/50;
	fuel.UpdateContent(to_string((int) (currentFuel * 100)) + " %");

	if (currentFuel <= 0)
	{
		// al menu
		printf("Sin gasolina");
	}
}

void Car::updatePosition(float dt)
{
	Vector2 oldPosition = transform.position;

	Vector2 targetPostion = InputManager::GetInstance().GetMousePosition();
	targetPostion.x -= (transform.size.x / 2);
	targetPostion.y -= (transform.size.y / 2);
	transform.position = transform.position.lerp(targetPostion, dt * 10);

	Vector2 direction = oldPosition.direction(targetPostion);
	currentForce = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (currentForce > 5) {
		double angle = atan2(direction.y, direction.x) - atan2(0, 1);
		angle *= (180 / M_PI);
		angle += 90;
		transform.rotation = angle;
	}
}

void Car::onCollisionEnter(GameObject* obj)
{
	if (Leaf* p = dynamic_cast<Leaf*>(obj))
	{
		Vector2 direction = transform.position.direction(p->transform.position);
		p->addForce(direction.normalize(), currentForce * maxForce);
	}
	else if (Fuel * p = dynamic_cast<Fuel*>(obj))
	{
		currentFuel += 0.2;
		if (currentFuel > 1)
		{
			currentFuel = 1;
		}
		destroy(p);
	}
}