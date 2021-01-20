#pragma once
#include "HUDElement.h"

class Text : public HUDElement
{
public:
	Text(Vector2 position, string text, SDL_Color color = {255, 255, 255}, string path = "../../Media/Fonts/pixel.TTF", int size = 28);
	~Text();
	void renderHUD() override;
	void UpdateContent(string content);

private:
	string fontPath;
	string content;
	SDL_Color color;
	int fontSize;
};
