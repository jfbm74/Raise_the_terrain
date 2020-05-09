#include "terrain.h"

int init_instance(SDL_Instance *instance)
{

    /* INICIALIZAR SDL*/
    if (SDL_Init(SDL_INIT_VIDEO != 0))
    {
        fprintf(stderr, "Unable to initialize SDL:  %s\n", SDL_GetError());
        return (1);
    }

    /* CREAR INSTANCIA DE NUEVA VENTANA*/
    instance->window = SDL_CreateWindow("Raise the terrain   by:Pipe \\o/", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (instance->window == NULL)
    {
        fprintf(stderr, "SDL_CreateWindow Error: %s", SDL_GetError());
        SDL_Quit();
        return (1);
    }

    /*CREAR UNA NUEVA INSTANCIA DE RENDERIZADO ENLAZADA A LA VENTANA CREADA MAS ARRIBA*/
    instance->renderer = SDL_CreateRenderer(instance->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (instance->renderer == NULL)
    {
        SDL_DestroyWindow(instance->window);
        fprintf(stderr, "SDL_CreateRenderer Error:  %s\n", SDL_GetError());
        SDL_Quit();
        return (1);
    }
    return (0);
}
