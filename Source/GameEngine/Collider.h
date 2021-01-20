#pragma once

class Collider {
public:
	double radius;
	bool isRect;
	bool isOnCollision;

	Collider();
	Collider(double radius);
	~Collider();
};