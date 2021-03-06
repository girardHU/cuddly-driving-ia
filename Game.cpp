#include "Game.hpp"

GameObject* player;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialised!..." << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "Window Created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255 ,255, 255);
            std::cout << "Renderer Created!" << std::endl;
        }

        int playerDimensions[4] = {414, 835, (int)(414 * 0.1), (int)(835 * 0.1)};
        int playerPosition[2] = {500, 500};
        player = new GameObject("assets/white-car.png", renderer, playerDimensions, playerPosition);

        isRunning = true;
    } else {
        isRunning = false;
    }
}

void Game::handleEvent()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            this->keyPressed(&event.key);
            break;
        case SDL_KEYUP:
            this->keyReleased(&event.key);
            break;
        default:
            break;
    }
}

void Game::update()
{
    cnt++;
    // std::cout << cnt << std::endl;

    // player->setDimensions(414, 835, 414 * 0.1, 835 * 0.1);
    player->update();
}

void Game::render()
{
    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    // This is where we would add stuff to render

    // Set render color to red ( background will be rendered in this color )
    // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Render Player
    player->render();

    // SDL_RenderFillRect(renderer, &rectangle);

    // Render the rect to the screen
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}

void Game::keyPressed(SDL_KeyboardEvent* event)
{
    std::cout << event->keysym.sym << std::endl;
    switch (event->keysym.sym) {
        case 1073741906: // haut
            // player->increaseYpos(-1);
            player->movePlayer(20);
            break;
        case 1073741905: // bas
            // player->increaseYpos(1);
            player->movePlayer(-20);
            break;
        case 1073741904: // gauche
            player->rotatePlayer(true);
            break;
        case 1073741903: // droite
            player->rotatePlayer(false);
            break;
    }
}

void Game::keyReleased(SDL_KeyboardEvent* event)
{
    std::cout << event->keysym.sym << std::endl;
}