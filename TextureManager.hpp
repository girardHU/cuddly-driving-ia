#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include "Game.hpp"

class TextureManager {

    public:
        static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* renderer);
};

#endif