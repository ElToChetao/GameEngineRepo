#include "Text.h"
#include "RenderManager.h"
Text::Text(Vector2 position, string text, SDL_Color color, string path, int size) :HUDElement(position)
{
	content = text;
	this->color = color;
	this->fontPath = path;
	this->fontSize = size;
	sprite.loadFromRenderedText(content, this->color, this->fontPath, this->fontSize);
	RenderManager::GetInstance().AddHUDElement(this);
}

Text::~Text()
{
}

void Text::renderHUD()
{
	sprite.render(position.x, position.y);
}
void Text::UpdateContent(string content) {
	sprite.loadFromRenderedText(content, this->color, this->fontPath, this->fontSize);
}