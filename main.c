#include "terrain.h"

/**
 * main - Funtion that draws a isometric figure
 * @argc: counter of arguments
 * @argv: value arguments
 * Return: 0 on Success
 */

int main(int argc, char **argv)
{
	SDL_Instance instance;
	SDL_bool running = SDL_TRUE;
	SDL_Event e;
	SDL_Point ***grid;
	int Angle;
	float a;

	if (argc != 2)
	{
		printf("Usage: ./terrain altitudes\n");
		return (EXIT_FAILURE);
	}
	if (init_instance(&instance) != 0)
		return (1);
	grid = populate_grid();
	convertoISO(grid, argv);
	draw_my_grid(instance.renderer, grid);
	freegrid(grid);
	while (running)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT ||
					(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
			{
				running = SDL_FALSE;
				break;
			}
			if (e.key.keysym.sym == SDLK_RIGHT)
				Angle = Angle + 1;
			else if (e.key.keysym.sym == SDLK_LEFT)
				Angle = Angle - 1;
			a = Angle * M_PI / 180;
			SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 255);
			SDL_RenderClear(instance.renderer);
			rotategrid(instance.renderer, argv, a);
		}
	}
	FreeSDL(instance.renderer, instance.window);
	return (0);
}
