#ifndef GAME_HPP
#define GAME_HPP

#include "SDL2/SDL.h"
#include <SDL2/SDL_test_images.h>
#include <iostream>

class Game {
    public:
        Game();
        ~Game();

        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvent();
        void update();
        void render();
        void clean();

        bool running() { return isRunning; }

    private:
        bool isRunning;
        SDL_Window *window;
        SDL_Renderer *renderer;
};

#endif