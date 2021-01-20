#pragma once
#include "Vector2.h"

class Transform {
	Vector2 force;
	double friction;

	double torqueForce;
public:
	Vector2 position;
	Vector2 size;
	Vector2 scale;

	double rotation;
	bool gravityEnabled;

	Transform();
	~Transform();

	void UpdatePhysics();
	void AddForce(Vector2 force);
	void AddTorque(double force);
	void SetFrictionValue(double value) { friction = value; };
};