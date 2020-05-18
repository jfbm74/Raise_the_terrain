#ifndef TERRAIN_H
#define TERRAIN_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <SDL.h>
#include <math.h>

#define WINDOW_WIDTH 1260
#define WINDOW_HEIGHT 680

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

/* INIT WINDOW CANVAS*/
int init_instance(SDL_Instance *);

int _atoi(char *);
char *_strdup(char *);
char **tokenize(char *, const char *);
void freearv(char **);
int **read_altitudes(char **);

SDL_Point ***alloc_mem(void);
SDL_Point ***populate_grid(void);
void convertoISO(SDL_Point ***, char **);

void All_isogrid(SDL_Renderer *, char **);
void draw_my_grid(SDL_Renderer *, SDL_Point ***);
void trans_to_rot(SDL_Point ***, float);
void rotategrid(SDL_Renderer *, char **, float );


void freegrid(SDL_Point ***);
void free2dArray(int **);
void FreeSDL(SDL_Renderer *, SDL_Window *);

#endif
