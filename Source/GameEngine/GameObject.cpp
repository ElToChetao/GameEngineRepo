#include "GameObject.h"
#include "GameObjectManager.h"

GameObject::GameObject() {
	isActive = true;
	GameObjectManager::GetInstance().AddGameObject(this);
}

GameObject::~GameObject()
{
	texture->free();
	delete texture;
	delete collider;
}

GameObject::GameObject(string tag) {
	isActive = true;
	setTag(tag);
	GameObjectManager::GetInstance().AddGameObject(this);
}

void GameObject::addCollider(double radius) {
	if (radius < 0)
	{
		collider = new Collider();
	}
	else
	{
		collider = new Collider(radius);
		transform.size.x = radius * 2;
		transform.size.y = radius * 2;
	}
}

Vector2 GameObject::getCenterPosition()
{
	return Vector2(transform.position.x + transform.size.x / 2, transform.position.y + transform.size.y / 2);
}

void GameObject::addSprite(string spritePath, int layer) {
	texture = RenderManager::GetInstance().GetSprite(spritePath, layer);
}

void GameObject::translate(Vector2 offset) {
	transform.position += offset * TimeManager::GetInstance().getDeltaTime();
}

void GameObject::rotate(double degree)
{
	transform.rotation += degree * TimeManager::GetInstance().getDeltaTime();
}

void GameObject::destroy(GameObject *other) {
	GameObjectManager::GetInstance().RemoveGameObject(other);
}

template <typename T>
T* GameObject::getComponent() 
{
	if (T* t = dynamic_cast<T*>(this))
	{
		return t;
	}
	return NULL;
}
