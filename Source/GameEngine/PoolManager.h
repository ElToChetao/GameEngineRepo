#pragma once
#include "Singleton.h"
#include "GameObject.h"
#include "SDL.h"
#include <vector>

template <typename T>
class Pool
{
	friend class Singleton<Pool>;
private:
	vector<T*> activeObjects;
	vector<T*> inactiveObjects;
public:
	Pool(int size) {
		for (int i = 0; i < size; i++)
		{
			Instantiate();
		}
	}
	void Instantiate() {
		inactiveObjects.push_back(new T());
	}
};

