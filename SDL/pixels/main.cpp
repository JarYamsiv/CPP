#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

void changePixles(Uint32 *pixels)
{
    static int itr=0;
    if(itr<WIDTH*HEIGHT)itr++;
    Uint32 color;
    Uint8 a, r, g, b;
    /*int t;
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            t = ((i * i) + (j * j) & 511) - 256;
            if (t < 0)
                t = -(t + 1);
            a = 0;
            r = 255 - t;
            g = t;
            b = t;
            color = (a << 24) | (r << 16) | (g << 8) | b;
            pixels[j * 640 + i] = color;
        }
    }*/
    a=255;r=255;g=50;b=50;
    color = (a << 24) | (r << 16) | (g << 8) | b;
    pixels[itr] = color;
}

int main(int argc, char **argv)
{
    bool leftMouseButtonDown = false;
    bool quit = false;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("SDL2 Pixel Drawing",
      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Texture *texture = SDL_CreateTexture(renderer,
       SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);

    Uint32 *pixels = new Uint32[WIDTH * HEIGHT];

    memset(pixels, 255, WIDTH * HEIGHT * sizeof(Uint32));
    Uint32 color;
    Uint8 a, r, g, b;
    int t;
    /*for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            t = ((i * i) + (j * j) & 511) - 256;
            if (t < 0)
                t = -(t + 1);
            a = 0;
            r = 255 - t;
            g = t;
            b = t;
            color = (a << 24) | (r << 16) | (g << 8) | b;
            pixels[j * 640 + i] = color;
        }
    }*/
    double elapsed_secs;

    while (!quit)
    {


        using namespace std;
        clock_t begin = clock();    
        changePixles(pixels);

        SDL_UpdateTexture(texture, NULL, pixels, 640 * sizeof(Uint32));

        

        SDL_WaitEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
            quit = true;
            break;
            case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                quit = true;
            break;
            case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT)
                leftMouseButtonDown = false;
            break;
            case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)
                leftMouseButtonDown = true;
            case SDL_MOUSEMOTION:
            if (leftMouseButtonDown)
            {
                a = 0;
                r = 0;
                g = 0;
                b = 255;
                color = (a << 24) | (r << 16) | (g << 8) | b;
                int mouseX = event.motion.x;
                int mouseY = event.motion.y;
                pixels[mouseY * 640 + mouseX] = color;
            }
            break;
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
        clock_t end = clock();
        elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    }

    std::cout << "avgtime= " <<elapsed_secs<<"\n";

    delete[] pixels;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}