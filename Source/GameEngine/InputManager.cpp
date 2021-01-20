#include "InputManager.h"

/*****************************************************************************/
InputManager::InputManager()
{
	mouseX = 0;
	mouseY = 0;
	mCurrentKeyStates = 0;
}

InputManager::~InputManager()
{

}

void InputManager::Update(void)
{
	mCurrentKeyStates = SDL_GetKeyboardState(NULL);

	keysDown.clear();
	keysUp.clear();

	for (int i = 0; i < 255; i++) {
		if (mCurrentKeyStates[i] != 0 && !KeyOnVector(i, keysPressed))
		{
			keysDown.push_back(i);
			keysPressed.push_back(i);
		}
		if (mCurrentKeyStates[i] == 0 && KeyOnVector(i, keysPressed))
		{
			keysPressed.erase(remove(keysPressed.begin(), keysPressed.end(), i), keysPressed.end());
			keysUp.push_back(i);
		}
	}

	SDL_GetMouseState(&mouseX, &mouseY);
}
/*****************************************************************************/

Vector2 InputManager::GetMousePosition() {
	return Vector2(mouseX, mouseY);
}

bool InputManager::GetKey(int scanCode)
{	
	return mCurrentKeyStates[scanCode] != 0;
}

bool InputManager::GetKeyDown(int scanCode)
{
	return KeyOnVector(scanCode, keysDown);
}

bool InputManager::GetKeyUp(int scanCode)
{
	return KeyOnVector(scanCode, keysUp);
}

bool InputManager::KeyOnVector(int code, vector<int> vec)
{
	return find(vec.begin(), vec.end(), code) != vec.end();
}

bool InputManager::GetMouseButton(int index)
{
	return SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(index);
}

/*******************************************************************************************/

float InputManager::GetAxis(string axis)
{
	float input = 0;
	if (axis == "Horizontal")
	{
		input = (float) mCurrentKeyStates[SDL_SCANCODE_A] - mCurrentKeyStates[SDL_SCANCODE_D];
	}
	else if (axis == "Vertical")
	{
		input = (float) mCurrentKeyStates[SDL_SCANCODE_S] - mCurrentKeyStates[SDL_SCANCODE_W];
	}
	else if (axis == "Horizontal Arrows")
	{
		input = (float) mCurrentKeyStates[SDL_SCANCODE_RIGHT] - mCurrentKeyStates[SDL_SCANCODE_LEFT];
	} 
	else if (axis == "Vertical Arrows")
	{
		input = (float) mCurrentKeyStates[SDL_SCANCODE_DOWN] - mCurrentKeyStates[SDL_SCANCODE_UP];
	}
	return input;
}