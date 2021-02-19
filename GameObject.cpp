#include "GameObject.hpp"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int dimensions[4], int playerPosition[2])
{
    renderer = ren;
    objTexture = TextureManager::LoadTexture(texturesheet, renderer);
    srcRect.h = dimensions[0];
    srcRect.w = dimensions[1];
    destRect.h = dimensions[2];
    destRect.w = dimensions[3];

    xpos = playerPosition[0];
    ypos = playerPosition[1];
    destRect.x = xpos;
    destRect.y = ypos;
}

void GameObject::update()
{



    // Will need to be adjusted
    // srcRect.x = 0;
    // srcRect.y = 0;
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

void GameObject::increaseXpos(int amount)
{
    std::cout << "In increaseXpos by " << amount << " !" << std::endl;
    this->xpos += amount;
}

void GameObject::increaseYpos(int amount)
{
    std::cout << "In increaseYpos by " << amount << " !" << std::endl;
    this->ypos += amount;
}