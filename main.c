#include "terrain.h"

int main(int argc, char **argv)
{
    int **grid_x;
    int **grid_y;
    int rows, cols = 0;
    SDL_Instance instance;
    SDL_Event e;
    bool quit = false;

    /* Check if Altitude File is added by main argument*/
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
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE))
            {
                printf("Bye!!!\n");
                quit = true;
            }
        }
        //Select surfaces based on key press
        switch (e.key.keysym.sym)
        {
        case SDLK_LEFT:
            printf("LEFT\n");
            break;
        case SDLK_RIGHT:
            printf("RIGTH\n");
            break;
        default:
            break;
        }

        //Clear screen
        SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
        SDL_RenderClear(instance.renderer);
        //DIBUJAMOS ALGO EN EL LIENZO DEBAJO DE ESTA LINEA
        SDL_RenderPresent(instance.renderer);
    }
    SDL_DestroyWindow(instance.window);
    SDL_Quit();

    return (0);
}