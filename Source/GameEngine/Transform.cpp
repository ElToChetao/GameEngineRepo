#include "Transform.h"
#include "TimeManager.h"
#include <math.h> 

Transform::Transform() {
	rotation = 0;
	friction = 0.99;
	force = Vector2::ZERO;
}

void Transform::UpdatePhysics()
{
	float dt = TimeManager::GetInstance().getDeltaTime();
	position += force * dt;
	force *= friction;
}

void Transform::AddForce(Vector2 force)
{
	this->force = force;
}
