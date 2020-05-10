#include "terrain.h"

int main(int argc, char **argv)
{
    SDL_Instance instance;
    SDL_Point ***grid;
    SDL_Event e;
    bool quit = false;

    /* Check if Altitude File is added by main argument*//*
    if (argc != 2)
    {
        printf("Error: Missing altitudes file\n");
        return (EXIT_FAILURE);
    }
    /* initialize a window and canvas */
    if (init_instance(&instance) != 0)
        return (1);
        
    while (!quit)
    {
        /*Handle events on queue*/
        while (SDL_PollEvent(&e) != 0)
        {
            /*User requests quit with ESCAPE Key*/
            if (e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE))
            {
                printf("Bye!!!\n");
                quit = true;
            }
        }

        /*Clear screen*/
        SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
        SDL_RenderClear(instance.renderer);
        /*Drawing from here*/
        grid = alloc_mem();
        populate_grid(grid);
        convertoISO(grid);
        draw_my_grid(instance.renderer, grid);
        SDL_RenderPresent(instance.renderer);
    }
    SDL_DestroyWindow(instance.window);
    SDL_Quit();

    return (0);
}