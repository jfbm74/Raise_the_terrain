#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#define WINDOW_WIDTH 1260
#define WINDOW_HEIGHT 680

typedef struct SDL_Instance
{
    SDL_Window *window;
    SDL_Renderer *renderer;
} SDL_Instance;

//Key press surfaces constants
enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};
/* INIT WINDOW CANVAS*/
int init_instance(SDL_Instance *);

#endif