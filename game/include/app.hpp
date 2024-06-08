#pragma once // #pragma once

// include std c++ libraries
#include <iostream>
#include <memory>

// Include SDL2 libraries
#include <SDL2/SDL.h>

// include local libraries

class App {
 private:
    bool isRunning_ = false;
    SDL_Window *window_;

 public:
    App();
    ~App();

    SDL_Renderer *renderer;

    enum class Mode { MainMenu, Game, Settings };

    void init(const char* title, int x, int y, int width, int height, Uint32 flags);

    bool isRunning() { return isRunning_; };
    void handleEvents();
    void update();
    void render();

    void cleanSDL();
};