#include "ManagerOfManagers.h"
#include "Leaf.h"
#include "Fuel.h"

using namespace std;

class Car :public GameObject
{
	public:
		HUDElement fuel = HUDElement(RenderManager::GetInstance().SCREEN_WIDTH * 0.5, RenderManager::GetInstance().SCREEN_HEIGHT * 0.95, "100 %");
		float currentFuel;
		float maxFuel;
		float currentForce;
		float maxForce;

		Car();
		void update() override;

		void updatePosition(float dt);
		void onCollisionEnter(GameObject*) override;
};