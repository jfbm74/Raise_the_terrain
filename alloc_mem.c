#include "terrain.h"

SDL_Point ***alloc_mem(void)
{
    int i;
    SDL_Point ***grid;

    
    grid = malloc(sizeof(SDL_Point **) * 2);
    grid[0] = malloc(sizeof(SDL_Point *) * 8);
    grid[1] = malloc(sizeof(SDL_Point *) * 8);
    for (i = 0; i < 8; i++)
    {
        grid[0][i] = malloc(sizeof(SDL_Point) * 8);
        grid[1][i] = malloc(sizeof(SDL_Point) * 8);
    }
    return (grid);
}
