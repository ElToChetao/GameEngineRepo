#pragma once
#include "ManagerOfManagers.h"
#include "Paddle.h"
class Ball : public GameObject {

private:
	Vector2 direction = Vector2::ONE;
	Vector2 startPosition;
	float speed = 150;

public:
	Ball() : GameObject() {
		addSprite("../../Media/Sprites/Pong/ball.png");
		addCollider(10);

		startPosition = RenderManager::GetInstance().GetScreenAdaptedPosition(0.5, 0.5);
		transform.position = startPosition;
	}
	void deviate() {
		float y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		direction.y = y;
	}
	void update() override {
		translate(direction * speed);
		rotate(speed * direction.x);

		if (transform.position.x < 0) 
		{
			GameObject* paddle = GameObjectManager::GetInstance().Find("rightPaddle");
			if (Paddle* p = dynamic_cast<Paddle*>(paddle))
			{
				p->updateScore();
			}

			transform.position = startPosition;
			direction.x = 1;
			speed = 200;
		}
		else if(transform.position.x > RenderManager::GetInstance().SCREEN_WIDTH - transform.size.x)
		{
			GameObject* paddle = GameObjectManager::GetInstance().Find("leftPaddle");
			if (Paddle* p = dynamic_cast<Paddle*>(paddle))
			{
				p->updateScore();
			}
			transform.position = startPosition;
			direction.x = -1;
			speed = 200;
		}

		if (transform.position.y < 0 || transform.position.y > RenderManager::GetInstance().SCREEN_HEIGHT - transform.size.y) {
			direction.y *= -1;
			AudioManager::GetInstance().PlaySound("../../Media/Sounds/1.wav", 20);
		}
	}
	void onCollisionEnter(GameObject* other) {
		if (other != NULL) {
			if (other->tag == "paddle") {
				direction = this->transform.position.direction(other->transform.position);
				direction = direction.normalize();
				speed *= 1.1;
			}
			AudioManager::GetInstance().PlaySound("../../Media/Sounds/1.wav", 20);
		}
	}
};