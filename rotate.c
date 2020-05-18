#include "terrain.h"

/**
 * trans_to_rot - transform x,y points with rotation
 * @grid: initial grid
 * @a: angle of rotation
 */
void trans_to_rot(SDL_Point ***grid, float a)
{
	int i, j, k, rotx, roty;

	for (k = 0; k < 2; k++)
	{
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				rotx = (grid[k][i][j].x - 1250) *
				 cos(a) - (grid[k][i][j].y - 350) *
				  sin(a) + 1250;
				roty = (grid[k][i][j].x - 1250) *
				 sin(a) + (grid[k][i][j].y - 350) *
				  cos(a) + 350;
				grid[k][i][j].x = rotx;
				grid[k][i][j].y = roty;
			}
		}
	}
}

/**
 * rotategrid - draw a grid and rotate it
 * @renderer: renderer
 * @argv: argument value
 * @a: angle
 */
void rotategrid(SDL_Renderer *renderer, char **argv, float a)
{
	SDL_Point ***rotate;

	rotate = populate_grid();
	trans_to_rot(rotate, a);
	convertoISO(rotate, argv);
	draw_my_grid(renderer, rotate);
	freegrid(rotate);
}
