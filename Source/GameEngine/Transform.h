#pragma once
#include "Vector2.h"

class Transform {
	Vector2 force;
	double friction;
	
public:
	Vector2 position;
	Vector2 size;
	Vector2 scale;

	double rotation;
	bool gravityEnabled;

	Transform();
	void UpdatePhysics();
	void AddForce(Vector2 force);
	void SetFrictionValue(double value) { friction = value; };
};