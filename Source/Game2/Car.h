#include "ManagerOfManagers.h"
#include "Leaf.h"

using namespace std;

class Car :public GameObject
{
	public:
		float currentFuel;
		float maxFuel;

		Car();
		void update() override;

		void updatePosition();
		void onCollisionEnter(GameObject*) override;
};