#include "Button.h"
#include "RenderManager.h"
#include "InputManager.h"

Button::Button(Vector2 position, string spritePath) :HUDElement(position) 
{
	sprite.loadFromFile(spritePath);
	RenderManager::GetInstance().AddHUDElement(this);
}
Button::Button(Vector2 position) : HUDElement(position)
{
}
bool Button::MouseOverButton()
{
	Vector2 mousePostion = InputManager::GetInstance().GetMousePosition();

	return mousePostion.x > position.x && mousePostion.x < position.x + sprite.getWidth() &&
		mousePostion.y > position.y && mousePostion.y < position.y + sprite.getHeight();
}

void Button::renderHUD()
{
	sprite.render(position.x, position.y);
}

void Button::addText(string content, SDL_Color color, string fontPath, int fontSize)
{
	sprite.loadFromRenderedText(content, color, fontPath, fontSize);
	RenderManager::GetInstance().AddHUDElement(this);
}
