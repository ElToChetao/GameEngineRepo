#include "Vector2.h"
#include <math.h>

const Vector2 Vector2::ZERO = Vector2();
const Vector2 Vector2::ONE = Vector2(1, 1);
const Vector2 Vector2::RIGHT = Vector2(1, 0);
const Vector2 Vector2::DOWN = Vector2(0, 1);
const Vector2 Vector2::LEFT = Vector2(-1, 0);
const Vector2 Vector2::UP = Vector2(0, -1);

Vector2::Vector2()
{
	x = 0.0;
	y = 0.0;
}

Vector2::Vector2(float a)
{
	this->x = a;
	this->y = a;
}

Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2 Vector2::direction(Vector2 a) {
	return Vector2(x - a.x, y - a.y);
}

Vector2 Vector2::normalize() {
	double magnitude = sqrt(x * x + y * y);

	return Vector2(x/magnitude, y/magnitude);
}

double Vector2::distance(Vector2 a, Vector2 b) {
	double deltaX = a.x - b.x;
	double deltaY = a.y - b.y;

	return sqrt(deltaX * deltaX + deltaY * deltaY);
}

Vector2& Vector2:: operator+=(const Vector2& other) {
	this->x += other.x;
	this->y += other.y;
	return *this;
}

Vector2& Vector2:: operator-=(const Vector2& other) {
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

Vector2& Vector2:: operator=(const Vector2& other) {
	this->x = other.x;
	this->y = other.y;
	return *this;
}

Vector2& Vector2:: operator-() {
	this->x = -x;
	this->y = -y;
	return *this;
}
