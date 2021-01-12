#include "HUDElement.h"
#include "RenderManager.h"

HUDElement::HUDElement(int x, int y, string text, SDL_Color color, string path, int size)
{
	position = Vector2(x, y);
	content = text;
	this->color = color;
	this->fontPath = path;
	this->size = size;
	sprite.loadFromRenderedText(content, this->color, this->fontPath, this->size);
	RenderManager::GetInstance().AddHUDElement(this);
}

void HUDElement::RenderText()
{
	sprite.render(position.x, position.y);
}
void HUDElement::UpdateContent(string content) {
	sprite.loadFromRenderedText(content, this->color, this->fontPath, this->size);
}