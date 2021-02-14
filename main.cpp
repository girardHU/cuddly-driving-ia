#include "Game.hpp"

Game *game = nullptr;

int main(int argc, const char * argv[])
{
    const int FPS = 50;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart = 0;
    int frameTime = 0;

    game = new Game();

    bool fullscreen = false;

    game->init("Driving", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, fullscreen);

    while (game->running())
    {
        frameStart = SDL_GetTicks();
        
        game->handleEvent();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        // Caps the game to 60 FPS
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}