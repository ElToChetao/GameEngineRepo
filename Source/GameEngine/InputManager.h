#pragma once

#include "Singleton.h"
#include "SDL.h"
#include "Vector2.h"
#include <vector>

/**
Input Manager class
*/
class InputManager :public Singleton<InputManager>
{
	/*****************************************************************************/
	friend class Singleton<InputManager>;
	/*****************************************************************************/

private:
	vector<int> keysPressed;
	vector<int> keysDown;
	vector<int> keysUp;
	
	int mouseX;
	int mouseY;

	const Uint8* mCurrentKeyStates;

	// Private constructor to avoid more than one instance
	InputManager();
	~InputManager();
	/*****************************************************************************/
	bool KeyOnVector(int code, vector<int> vec);
public:
	
	void Update( void );

	bool GetKey( int scanCode );
	bool GetKeyDown(int scanCode);
	bool GetKeyUp(int scanCode);

	Vector2 GetMousePosition();
	bool GetMouseButton(int index);

	float GetAxis(string axis);

	/*****************************************************************************/

};