#include <iostream>
#include "SDL/include/SDL2/SDL.h"

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *Window = SDL_CreateWindow("test", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    if(Window == NULL) {
        std::cerr << "Window not windowing!" << SDL_GetError() << "\n";
        return 1;
    }

    SDL_Event WindowEvent;

    while(true) {
        if(SDL_PollEvent(&WindowEvent)) {
            if(SDL_QUIT == WindowEvent.type) {
                break;
            }
        }
    }

    SDL_DestroyWindow(Window);
    SDL_Quit();

    return EXIT_SUCCESS;
}