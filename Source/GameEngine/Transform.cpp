#include "Transform.h"
#include "PhysicsManager.h"
#include "TimeManager.h"
#include <math.h> 

Transform::Transform() 
{
	rotation = 0;
	friction = 0.99;
	force = Vector2::ZERO;
	gravityEnabled = false;
}

Transform::~Transform()
{

}

void Transform::UpdatePhysics()
{
	float dt = TimeManager::GetInstance().getDeltaTime();
	position += force * dt;
	rotation += torqueForce * dt;

	force *= friction;
	torqueForce *= friction;

	if (gravityEnabled) {
		position -= Vector2::UP * PhysicsManager::GetInstance().gravity;
	}
}

void Transform::AddForce(Vector2 force)
{
	this->force = force;
}
void Transform::AddTorque(double force)
{
	torqueForce = force;
}
