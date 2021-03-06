#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "Game.hpp"
#include "TextureManager.hpp"
// #include <SDL/SDL_rotozoom.h>

class GameObject {
    public:
        GameObject(const char* texturesheet, SDL_Renderer* renderer, int dimensions[4], int playerPosition[2]);
        ~GameObject();

        void update();
        void render();
        void setDimensions(int srcH, int srcW, int destH, int destW);
        void movePlayer(int velocity);

        void rotatePlayer(bool counterClockwise);

        int angle = 0;

    private:
        int xpos;
        int ypos;

        SDL_Texture* objTexture;
        SDL_Rect srcRect, destRect;
        SDL_Surface* rotatedImage;
        SDL_Renderer* renderer;
};

#endif