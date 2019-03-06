#include "../headers/engine.h"
#include <iostream>

engine::engine()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }

    window = SDL_CreateWindow(
        "SDL Tutorial",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }
    //SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == 0)
    {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
    //SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    screenSurface = SDL_GetWindowSurface(window);
    //Fill the surface white
    SDL_Rect rc = {0, 0, 100, 100};
    SDL_FillRect(screenSurface, &rc, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    //Update the surface
    SDL_UpdateWindowSurface(window);
}
engine::~engine()
{
    if (screenSurface)
    {
        SDL_FreeSurface(screenSurface);
    }
    if (window)
    {
        SDL_DestroyWindow(window);
    }
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
    }
    //Quit SDL subsystems
    SDL_Quit();
}

void engine::run()
{
    running = true;
    std::thread evntloop(&engine::eventThread, this);
    while (running)
    {   
        //clear
        SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

        SDL_Rect rc = {100, 100, 100, 100};
        SDL_FillRect(screenSurface, &rc, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0xFF));

        //rendering
        SDL_UpdateWindowSurface(window);
    }
    evntloop.join();
}

void engine::eventThread()
{
    while (running)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                running = false;
            break;
        }
    }
}
