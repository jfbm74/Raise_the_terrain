#include "terrain.h"

void populate_grid(SDL_Point ***grid)
{
    int i, j, x = 800, y = 0;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            grid[0][i][j].x = x;
            grid[0][i][j].y = y;
            x = grid[0][i][j].x + 50;
        }
        x = 800;
        y += 50;
    }
    /**CREATING X,Y POINTS FOR COLUMN DRAWING*/
    i, j, x = 800, y = 0;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            grid[1][i][j].x = x;
            grid[1][i][j].y = y;
            y = grid[1][i][j].y + 50;
        }
        y = 0;
        x += 50;
    }
}
