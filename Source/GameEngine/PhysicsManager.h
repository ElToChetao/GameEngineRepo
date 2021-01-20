#pragma once

#include "Singleton.h"
#include "SDL.h"
#include "GameObjectManager.h"

class PhysicsManager :public Singleton<PhysicsManager>
{
	/*****************************************************************************/
	friend class Singleton<PhysicsManager>;
	/*****************************************************************************/

private:
	// Private constructor to avoid more than one instance
	PhysicsManager();
	~PhysicsManager();

	double DistanceSquared(double x1, double y1, double x2, double y2);

	bool CheckCollisions(GameObject* go, GameObject* other);

	bool CheckCircleCollisions(GameObject* go, GameObject* other);
	bool CheckCircleCollisions(Vector2 position, double radius, GameObject* other);

	bool CheckRectCollisions(GameObject* go, GameObject* other);

	bool CheckRectCircleCollisions(GameObject* rect, GameObject* circle);
	bool CheckRectCircleCollisions(GameObject* rect, Vector2 centerCircle, double radius);
	void UpdateState(GameObject* go, bool collision, GameObject* go2);

public:
	double gravity = 9.8;


	void Update();
	GameObject* CheckSphere (Vector2 position, double radius, GameObject* self);

	/*****************************************************************************/
};