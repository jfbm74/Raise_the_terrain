#include "terrain.h"

/**
 * draw_my_grid - Funciton to draw a grid
 * @renderer: renderer
 * @grid: grid
 */
void draw_my_grid(SDL_Renderer *renderer, SDL_Point ***grid)
{
	int i;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (i = 0; i < 8; i++)
		SDL_RenderDrawLines(renderer, grid[0][i], 8);
	for (i = 0; i < 8; i++)
		SDL_RenderDrawLines(renderer, grid[1][i], 8);
	SDL_RenderPresent(renderer);
}
