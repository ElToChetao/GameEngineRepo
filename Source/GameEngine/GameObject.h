#pragma once

#include "Transform.h"
#include "SDL.h"
#include "Collider.h"
#include "RenderManager.h"
#include "TimeManager.h"
#include "Entity.h"
#include <Texture.h>
#include <string>
using namespace std;

class GameObject : public Entity {	
public:
	Transform transform;
	bool isActive;

	LTexture* texture  = NULL;
	Collider* collider = NULL;

	GameObject();
	GameObject(string tag);
	~GameObject();

	void translate(Vector2 offset);
	void rotate(double degree);
	void destroy(GameObject* other);

	void addCollider(double radius = -1);
	void addSprite(string spritePath, int layer = 3);

	virtual void update() {};
	virtual void onDestroy() {};

	virtual void onCollisionStay(GameObject *other) {};
	virtual void onCollisionEnter(GameObject* other) {};
	virtual void onCollisionExit(GameObject* other) {};

	Vector2 getCenterPosition();
};