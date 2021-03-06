#pragma once

#include "SDL.h"
#include "SDL_image.h"

#include <string>

//Texture wrapper class
class LTexture
{
private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
	int layer;

public:
  //Initializes variables
  LTexture();

  //Deallocates memory
  ~LTexture();

  void setLayer(int);
  int getLayer() { return layer; }

  //Loads image at specified path
  bool loadFromFile(std::string path);

  //Deallocates texture
  void free();

  //Set color modulation
  void setColor(Uint8 red, Uint8 green, Uint8 blue);

  //Set blending
  void setBlendMode(SDL_BlendMode blending);

  //Set alpha modulation
  void setAlpha(Uint8 alpha);

  //Renders texture at given point
  void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

  //Gets image dimensions
  int getWidth();
  int getHeight();

  bool loadFromRenderedText(std::string textureText, SDL_Color textColor, std::string path, int size);

  //Image path
  std::string spritePath;
};