#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* filename, SDL_Renderer* renderer)
{
    SDL_Surface* tempSurface = IMG_Load(filename);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return tex;
}