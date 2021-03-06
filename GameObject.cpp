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
    // SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
    SDL_RenderCopyEx(renderer, objTexture, NULL, &destRect, angle, NULL, SDL_FLIP_NONE);
}

void GameObject::movePlayer(int velocity)
{
    std::cout << "Moving by " << velocity << " !" << std::endl;

    double pi = 2 * acos(0.0);

    float x_movement = cos(angle * (pi / 180)) * velocity;
    float y_movement = sin(angle * (pi / 180)) * velocity;
    this->xpos += x_movement;
    this->ypos += y_movement;
}

void GameObject::rotatePlayer(bool counterClockwise)
{
    if (counterClockwise)
    {
        this->angle -= 3;
    } else
    {
        this->angle += 3;
    }
    if (this->angle >= 360 || this->angle <= -360)
    {
        this->angle = 0;
    }
    std::cout << "angle : " << angle << std::endl;
}