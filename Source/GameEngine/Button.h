#pragma once
#pragma once
#include <string>
#include "SDL.h"
#include "InputManager.h"
#include "GameObject.h"
#include "HUDElement.h"

using namespace std;

class Button : public GameObject, Text {
private:
	bool mouseOver = false;
public:
	Button(Vector2 position, Vector2 size) :GameObject(position), Text(position, "SAMPLETEXT") {
		transform.size = size;
		
	};
	void update() override {
		Vector2 mousePosition = InputManager::GetInstance().GetMousePosition();

		if (mousePosition.x > transform.position.x && mousePosition.x < transform.position.x + transform.size.x &&
			mousePosition.y > transform.position.y && mousePosition.y < transform.position.y + transform.size.y)
		{
			mouseOver = true;
		}
		else 
		{
			mouseOver = false;
		}

		if (mouseOver && InputManager::GetInstance().GetMouseButton(1)) {
			onClick();
			printf("DORAEMON\n");
		}
	}

	virtual void onClick() {};
};