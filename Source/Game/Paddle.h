#pragma once
#include "ManagerOfManagers.h"

class Paddle : public GameObject {
private:
	float speed = 500;
	int score = 0;
	HUDElement* scoreText;
public:
	string axis;
	Paddle(Vector2 startPosition, string spritePath, string axis, Vector2 hudPos) {
		addSprite(spritePath);
		setTag("paddle");

		transform.position = startPosition;

		transform.size.x = 32;
		transform.size.y = 32;

		addCollider();
		this->axis = axis;

		scoreText = new HUDElement(hudPos.x, hudPos.y, to_string(0));
	}
	void update() override {
		translate(Vector2(0, 1) * InputManager::GetInstance().GetAxis(axis) * speed);
		transform.position.y = transform.position.y < 30 ? 30 : (transform.position.y > RenderManager::GetInstance().SCREEN_HEIGHT - 60) ?
			RenderManager::GetInstance().SCREEN_HEIGHT - 60 : transform.position.y;
	}
	void updateScore() {
		score++;
		scoreText->UpdateContent(to_string(score));
	}
};