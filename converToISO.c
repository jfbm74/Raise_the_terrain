#include "terrain.h"

void convertoISO(SDL_Point ***grid)
{
    int i, j, WX, WY;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            WX = (0.7 * grid[0][i][j].x) - 0.7 * (grid[0][i][j].y);
            WY = (0.3 * grid[0][i][j].x) + 0.3 * (grid[0][i][j].y);
            grid[0][i][j].x = WX;
            grid[0][i][j].y = WY;
        }
    }

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            WX = 0.7 * grid[1][i][j].x - 0.7 * grid[1][i][j].y;
            WY = 0.3 * grid[1][i][j].x + 0.3 * grid[1][i][j].y;
            grid[1][i][j].x = WX;
            grid[1][i][j].y = WY;
        }
    }
}