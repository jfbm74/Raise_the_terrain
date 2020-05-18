#include "terrain.h"

/**
 * populate_grid - creates and populates x,y grid
 * Return: grid
 */
SDL_Point ***populate_grid(void)
{
	int i, j, x = 800, y = 0;
	SDL_Point ***grid;

	grid = alloc_mem();
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			grid[0][i][j].x = x;
			grid[0][i][j].y = y;
			x = x + 50;
		}
		x = 800;
		y = y + 50;
	}

	x = 800, y = 0;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			grid[1][i][j].x = x;
			grid[1][i][j].y = y;
			y = y + 50;
		}
		y = 0;
		x = x + 50;
	}
	return (grid);
}
