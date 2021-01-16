#pragma once
#include "ManagerOfManagers.h"
#include "Text.h"
class Paddle : public GameObject {
private:
	float speed = 500;
	int score = 0;
	Text* scoreText;
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

		scoreText = new Text(hudPos, to_string(0));
	}
	void update() override {
		translate(Vector2(0, 1) * InputManager::GetInstance().GetAxis(axis) * speed);
		transform.position.y = transform.position.y < 0 ? 0 : (transform.position.y > RenderManager::GetInstance().SCREEN_HEIGHT - transform.size.y) ?
			RenderManager::GetInstance().SCREEN_HEIGHT - transform.size.y : transform.position.y;
	}
	void updateScore() {
		score++;
		scoreText->UpdateContent(to_string(score));
	}
};