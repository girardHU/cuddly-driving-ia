#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "Game.hpp"
#include "TextureManager.hpp"

class GameObject {
    public:
        GameObject(const char* texturesheet, SDL_Renderer* renderer, int dimensions[4], int playerPosition[2]);
        ~GameObject();

        void update();
        void render();
        void setDimensions(int srcH, int srcW, int destH, int destW);

    private:
        int xpos;
        int ypos;

        SDL_Texture* objTexture;
        SDL_Rect srcRect, destRect;
        SDL_Renderer* renderer;
};

#endif