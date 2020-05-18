#include "terrain.h"
/**
 * convertoISO - tansform a grid into isometric view
 * @grid: array of x,y points
 * @argv: argument value
 */
void convertoISO(SDL_Point ***grid, char **argv)
{
	int **alt;
	int i, j, WX, WY;

	alt = read_altitudes(argv);

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			WX = 0.7 * grid[0][i][j].x - 0.7 * grid[0][i][j].y;
			WY = 0.3 * grid[0][i][j].x + 0.3 * grid[0][i][j].y - alt[i][j];
			grid[0][i][j].x = WX;
			grid[0][i][j].y = WY;
		}
	}

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			WX = 0.7 * grid[1][i][j].x - 0.7 * grid[1][i][j].y;
			WY = 0.3 * grid[1][i][j].x + 0.3 * grid[1][i][j].y - alt[j][i];
			grid[1][i][j].x = WX;
			grid[1][i][j].y = WY;
		}
	}

	free2dArray(alt);
}
