#pragma once

#include "Singleton.h"
#include "SDL.h"
#include "SDL_image.h"
#include <Texture.h>
#include "HUDElement.h"
#include <vector>

/**
Render Manager class
*/
class RenderManager :public Singleton<RenderManager>
{
	/*****************************************************************************/
	friend class Singleton<RenderManager>;
	/*****************************************************************************/

	private:

		//The window we'll be rendering to
		SDL_Window* mWindow = NULL;

		//The window renderer
		SDL_Renderer* mRenderer = NULL;

		// Private constructor to avoid more than one instance
		RenderManager();
		~RenderManager();
		/*****************************************************************************/

	public:
		//Screen dimension constants
		static const int SCREEN_WIDTH = 640;
		static const int SCREEN_HEIGHT = 480;
		vector <LTexture*> sprites;
		vector <HUDElement*> hud;

		//Functions
		bool Init();

		void Update();

		LTexture* GetSprite(string spritePath);

		void AddHUDElement(HUDElement* hudElement);

		SDL_Window* GetWindow() { return mWindow; }

		SDL_Renderer* GetRenderer() { return mRenderer; }

		Vector2 GetScreenAdaptedPosition(float x, float y) { return Vector2(SCREEN_WIDTH * x, SCREEN_HEIGHT * y); }

		/*****************************************************************************/
};
