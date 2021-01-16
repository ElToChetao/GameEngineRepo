#include "ManagerOfManagers.h"
#include "Leaf.h"
#include "Fuel.h"
#include "Text.h"

using namespace std;

class Car :public GameObject
{
	public:
		Text fuel = Text(Vector2(RenderManager::GetInstance().GetScreenAdaptedPosition(0.5, 0.95)), "100 %", {255, 0, 0});
		float currentFuel;
		float maxFuel;
		float currentForce;
		float maxForce;

		Car();
		void update() override;

		void updatePosition(float dt);
		void onCollisionEnter(GameObject*) override;
};