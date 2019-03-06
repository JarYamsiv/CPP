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
	SDL_Window *window;
	SDL_Surface *screenSurface;
	SDL_Renderer *renderer;
};

#endif