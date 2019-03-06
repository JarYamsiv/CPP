#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

#define pel(surf, x, y, rgb) ((unsigned char *)(surf->pixels))[y*(surf->pitch)+x*3+rgb]



int main(int argc, char *args[])
{
    SDL_Window *window = NULL;
    SDL_Surface *scr = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
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

    //Get window surface
    scr = SDL_GetWindowSurface(window);
    //Fill the surface white

    SDL_LockSurface(scr);
    int x,y,t;
    for(y = 0; y < scr->h; y++)
        for(x = 0; x < scr->w; x++)
        {
                /* This is what generates the pattern based on the xy co-ord */
                t = ((x*x + y*y) & 511) - 256;
                if (t < 0)
                        t = -(t + 1);

                /* Now we write to the surface */
                pel(scr, x, y, 0) = 255 - t; //red
                pel(scr, x, y, 1) = t; //green
                pel(scr, x, y, 2) = t; //blue
        }
    SDL_UnlockSurface(scr);


    SDL_FillRect(scr, NULL, SDL_MapRGB(scr->format, 0xFF, 0xFF, 0xFF));
    //Update the surface
    SDL_UpdateWindowSurface(window);
    int Running = 1;
    while (Running)
    {
        SDL_Event Event;
        while (SDL_PollEvent(&Event))
        {
            if (Event.type == SDL_KEYDOWN)
            {
                switch (Event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    Running = 0;
                    break;
                default:
                    break;
                }
            }
            else if (Event.type == SDL_QUIT)
            {
                Running = 0;
            }
        }
    }

    SDL_DestroyWindow(window);
    //Quit SDL subsystems
    SDL_Quit();
    return 0;
}
