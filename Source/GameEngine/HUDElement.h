#pragma once
#include <Texture.h>
#include <string>
#include "Vector2.h"

using namespace std;

class HUDElement {
private:
public:
	HUDElement(Vector2 position) 
	{ 
		this->position = position; 
		isActive = true;
	};
	Vector2 position;
	LTexture sprite;
	bool isActive;
	virtual void renderHUD() {};
};