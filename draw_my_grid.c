#include "terrain.h"

void draw_my_grid(SDL_Renderer *renderer, SDL_Point ***grid)
{
    int i;
    /* Selecting color of "pencil" to draw*/
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    /* Painting all the rows*/
    for (i = 0; i < 8; i++)
        SDL_RenderDrawLines(renderer, grid[0][i], 8);
    /* Painting all the cols*/
    for (i = 0; i < 8; i++)
        SDL_RenderDrawLines(renderer, grid[1][i], 8);
}
