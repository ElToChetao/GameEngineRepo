#include "Leaf.h"

Leaf::Leaf(Vector2 position):GameObject()
{
	this->currentSpeed = 0;
	this->direction = Vector2::ZERO;

	transform.position = position;
	
	transform.rotation = rand() % 360;
	int option = rand() % 3;

	switch (option)
	{
		case 0:
			addSprite("../../Media/Sprites/CarLeaf/leaves0.png", 2);
			break;
		case 1:
			addSprite("../../Media/Sprites/CarLeaf/leaves1.png", 2);
			break;
		case 2:
			addSprite("../../Media/Sprites/CarLeaf/leaves2.png", 2);
			break;
	}
	
	addCollider(32);
	transform.SetFrictionValue(0.97);

	double x = -10 + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (30 + 10)));
	double y = -10 + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (30 + 10)));

	double r = -10 + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (30 + 10)));
	transform.AddForce(Vector2(x, y));
	transform.AddTorque(30);
}

Leaf::~Leaf()
{

}

void Leaf::update()
{
	float dt = TimeManager::GetInstance().getDeltaTime();
	if(transform.position.x < 0 || transform.position.x >= RenderManager::GetInstance().SCREEN_WIDTH
	|| transform.position.y < 0 || transform.position.y >= RenderManager::GetInstance().SCREEN_HEIGHT)
	{
		LeafManager* p = dynamic_cast<LeafManager*>(GameObjectManager::GetInstance().GetManager("LeafManager"));
		if (p != nullptr)
		{
			p->addPoint();
		}
		AudioManager::GetInstance().PlaySound("../../Media/Sounds/leaf.wav");
		destroy(this);
	}
}

void Leaf::leafMovement(float dt)
{
	transform.position += direction * currentSpeed * dt;

	currentSpeed *= 0.98;
}

void Leaf::addForce(Vector2 direction, float magnitude)
{
	transform.AddForce(-direction * magnitude);
	transform.AddTorque(magnitude);
}