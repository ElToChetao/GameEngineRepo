#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "Transform.h"
#include <Texture.h>

#include <string>
using namespace std;

class HUDElement {
private:
	LTexture sprite;
	string fontPath;
public:
	Vector2 position;
	string content;
	SDL_Color color;
	int size;

	HUDElement(int x, int y, string text, SDL_Color color = { 0, 0, 0 }, string fontPath = "../../Media/Fonts/pixel.TTF", int size = 28);
	void RenderText();
	void UpdateContent(string content);
};