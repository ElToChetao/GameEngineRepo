#pragma once

#include "Transform.h"
#include "SDL.h"
#include "Collider.h"
#include "RenderManager.h"
#include "TimeManager.h"
#include <Texture.h>
#include <string>
using namespace std;

class GameObject {	
public:
	Transform transform;

	bool isActive;
	
	string name;
	string tag;

	LTexture* texture  = NULL;
	Collider* collider = NULL;

	GameObject();
	GameObject(string tag);

	void translate(Vector2 offset);
	void rotate(double degree);
	void destroy(GameObject* other);

	void addCollider(double radius = -1);
	void addSprite(string spritePath, int layer = 3);

	void setActive(bool b) { isActive = b; }
	void setTag(string tag) { this->tag = tag; }

	template <typename T>
	T* getComponent();

	virtual void update() {};
	virtual void onDestroy() {};
	virtual void onCollisionStay(GameObject *other) {};
	virtual void onCollisionEnter(GameObject* other) {};
	virtual void onCollisionExit(GameObject* other) {};

	Vector2 getCenterPosition();
};