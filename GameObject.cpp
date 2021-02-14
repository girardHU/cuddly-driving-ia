#include "GameObject.hpp"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int dimensions[4])
{
    renderer = ren;
    objTexture = TextureManager::LoadTexture(texturesheet, renderer);
    srcRect.h = dimensions[0];
    srcRect.w = dimensions[1];
    destRect.h = dimensions[2];
    destRect.w = dimensions[3];
}

void GameObject::update()
{
    xpos = 0;
    ypos = 0;

    // Will need to be adjusted
    srcRect.x = 0;
    srcRect.y = 0;
    // srcRect.h = 32;
    // srcRect.w = 32;

    destRect.x = xpos;
    destRect.y = ypos;
    // destRect.h = 32 * 2;
    // destRect.w = 32 * 2;
}

void GameObject::render()
{
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}