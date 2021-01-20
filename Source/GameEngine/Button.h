#pragma once
#include "HUDElement.h"
#include "Text.h"
class Button : public HUDElement
{
	private:
	public:
		Button(Vector2 position);
		Button(Vector2 position, string spritePath);
		bool MouseOverButton();
		bool Pressed();
		void renderHUD() override;
		void addText(string text, SDL_Color color = { 255, 255, 255 }, string fontPath = "../../Media/Fonts/pixel.TTF", int fontSize = 28);
};

