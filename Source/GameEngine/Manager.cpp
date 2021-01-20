#include "Manager.h"
#include "GameObjectManager.h"

Manager::Manager() {
	GameObjectManager::GetInstance().AddManager(this);
}

Manager::Manager(string tag) {
	setTag(tag);
	GameObjectManager::GetInstance().AddManager(this);
}

void Manager::destroy(GameObject* other) 
{
	GameObjectManager::GetInstance().RemoveGameObject(other);
}
