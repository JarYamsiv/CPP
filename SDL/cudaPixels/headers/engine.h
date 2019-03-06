#ifndef ENGINE_H
#define ENGINE_H

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#include <SDL2/SDL.h>
#include <thread>

class engine
{
public:
	engine();
	~engine();
	void run();

private:
	int running;
	SDL_Event event;
	void eventThread();
	void initSDL();
	void initCUDA();
	SDL_Window *window;
	SDL_Surface *screenSurface;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	Uint32 *pixels;
};

#endif