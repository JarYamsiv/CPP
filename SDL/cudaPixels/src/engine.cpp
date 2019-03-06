#include "../headers/engine.h"
#include <iostream>

engine::engine()
{
    initSDL();

    pixels = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    memset(pixels, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    
    int t;

    Uint8 a,r,g,b;
    Uint32 color;
    for(int i=0; i<SCREEN_WIDTH; i++)
    {
        for(int j=0; j<SCREEN_HEIGHT; j++)
        {
            t = ((i * i) + (j * j) & 511) - 256;
            if (t < 0)
                t = -(t + 1);
            a = 0;
            r = 255 - t;
            g = t;
            b = t;
            color = (a << 24) | (r << 16) | (g << 8) | b;
            pixels[j * SCREEN_WIDTH + i] = color;
        }
    }
    SDL_UpdateTexture(texture, NULL, pixels, SCREEN_WIDTH * sizeof(Uint32));
}

void engine::initSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }

    window = SDL_CreateWindow(
        "Cuda Pixels",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer == 0)
    {
        printf("failed to create renderer\n");
    }

    texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);

    if(texture == 0)
    {
        printf("failed to create texture\n");
    }
}
void engine::initCUDA()
{
    
}

engine::~engine()
{
    if (window)
    {
        SDL_DestroyWindow(window);
    }
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
    }
    if ( texture)
    {
        SDL_DestroyTexture(texture);
    }
    delete [] pixels;
    //Quit SDL subsystems
    SDL_Quit();
}

void engine::run()
{
    running = true;
    std::thread evntloop(&engine::eventThread, this);
    while (running)
    {   
        SDL_UpdateTexture(texture, NULL, pixels, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
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


