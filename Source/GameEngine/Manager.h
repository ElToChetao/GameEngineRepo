#pragma once

#include <string>
#include "GameObject.h"
using namespace std;

class Manager : public Entity {

public:
	Manager();
	Manager(string tag);

	void destroy(GameObject* other);

	virtual void update() {};
};