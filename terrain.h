#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define WINDOW_WIDTH 1260
#define WINDOW_HEIGHT 680

typedef struct SDL_Instance
{
    SDL_Window *window;
    SDL_Renderer *renderer;
} SDL_Instance;

/* INIT WINDOW CANVAS*/
int init_instance(SDL_Instance *);

/* fill rows and cols*/
SDL_Point ***alloc_mem(void);
void populate_grid(SDL_Point ***grid);
void convertoISO(SDL_Point ***isogrid);
void draw_my_grid(SDL_Renderer *renderer, SDL_Point ***grid);


#endif