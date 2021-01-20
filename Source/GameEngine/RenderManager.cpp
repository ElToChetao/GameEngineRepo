#include "RenderManager.h"
#include "GameObjectManager.h"
#include <SDL_ttf.h>

#include <algorithm>
/*****************************************************************************/

RenderManager::RenderManager(void)
{
}

/*****************************************************************************/

RenderManager::~RenderManager(void)
{
      //Destroy window	
      SDL_DestroyRenderer(mRenderer);
      SDL_DestroyWindow(mWindow);

      mWindow = NULL;
      mRenderer = NULL;

      for (int i = 0; i < sprites.size(); i++)
      {
          sprites[i]->free();
      }

      sprites.clear();

      for (int i = 0; i < hud.size(); i++)
      {
          hud[i]->sprite.free();
      }

      hud.clear();

      //Quit SDL subsystems
      TTF_Quit();
      IMG_Quit();
}

/*****************************************************************************/

bool RenderManager::Init(int w, int h)
{
  //Initialization flag
  bool success = true;

  //Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    success = false;
  }
  else
  {
    //Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
    {
      printf("Warning: Linear texture filtering not enabled!");
    }

    //Create window
    SCREEN_WIDTH = w;
    SCREEN_HEIGHT = h;
    mWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (mWindow == NULL)
    {
      printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
      success = false;
    }
    else
    {
      //Create vsynced renderer for window
      mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
      if (mRenderer == NULL)
      {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        success = false;
      }
      else
      {
        //Initialize renderer color
        SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 0xFF);

        //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags))
        {
          const char *error = IMG_GetError();
          printf("SDL_image could not initialize! SDL_image Error: %s\n", error);
          success = false;
        }

        //Initialize SDL_ttf
        if (TTF_Init() == -1)
        {
            printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
            success = false;
        }
      }
    }
  }
    
  //Load all images

  return success;
}

/*****************************************************************************/

void RenderManager::Update()
{
    // clear screen
    SDL_RenderClear(GetRenderer());

    //get al rendereable objets form gameobjectmanager
    vector<GameObject*> go = GameObjectManager::GetInstance().GetGameObjects();

    for (int layer = 1; layer <= 3; layer++) {
        for (int i = 0; i < go.size(); i++) {
            if (go[i]->texture != NULL && go[i]->texture->getLayer() == layer) {
                go[i]->texture->render(go[i]->transform.position.x, go[i]->transform.position.y, NULL, go[i]->transform.rotation);
            }
        }
    }
    go.clear();

    for (int i = 0; i < hud.size(); i++) {
        if (hud[i]->isActive) {
            hud[i]->renderHUD();
        }
    }
    //render screen
    SDL_RenderPresent(GetRenderer());
}
LTexture* RenderManager::GetSprite(string spritePath, int layer)
{
    // check if sprite is already loaded

    for (int i = 0; i < sprites.size(); i++) {
        if (sprites[i]->spritePath._Equal(spritePath)) {
            // sprite already loaded
            return sprites[i];
        }
    }

    printf("adding new sprite\n");
    // sprite not found
    LTexture *tempSprite = new LTexture();

    if (!tempSprite->loadFromFile(spritePath)) {
        printf("Path not found");
        return nullptr;
    }
    else 
    {
        tempSprite->setLayer(layer);
        sprites.push_back(tempSprite);
        return sprites[sprites.size() - 1];
    }
}

void RenderManager::AddHUDElement(HUDElement* hudElement)
{
    hud.push_back(hudElement);
}

/*****************************************************************************/
