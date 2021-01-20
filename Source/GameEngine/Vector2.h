#pragma once

class Vector2 {
public:
	static const Vector2 ZERO;
	static const Vector2 ONE;
	static const Vector2 RIGHT;
	static const Vector2 DOWN;
	static const Vector2 LEFT;
	static const Vector2 UP;

	double x;
	double y;

	Vector2();
	Vector2(double x, double y);
	Vector2(double a);
	~Vector2();

	Vector2 direction(Vector2 a);
	Vector2 normalize();
	Vector2 lerp(Vector2 other, double t);
	double distance(Vector2 a, Vector2 b);

	Vector2& operator+=(const Vector2& other);
	Vector2& operator-=(const Vector2& other);
	Vector2& operator*=(const Vector2& other);
	Vector2& operator*=(const double& value);
	const Vector2 operator * (double v) const { return Vector2(x * v, y * v); }
	Vector2& operator=(const Vector2& other);
	Vector2& operator-();
};
