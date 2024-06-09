#pragma once // #pragma once

// include std c++ libraries
#include <iostream>
#include <memory>

// Include SDL2 libraries
#include <SDL2/SDL.h>

// include local libraries
#include "./app_mode.hpp"

class App {
 public:
    App();
    ~App();

    enum class Mode { MainMenu, Game, Settings }; // Enum class with all application modes
    void setMode(Mode newMode); // Method used for switching App modes

    static SDL_Renderer *renderer;

    void init(const char* title, int x, int y, int width, int height, Uint32 flags);

    bool isRunning() { return isRunning_; };
    
    void handleEvents();
    void update();
    void render();

    void clean();

 private:
    bool isRunning_ = false;
    SDL_Window *window_;
    Mode currentMode_;
    std::unique_ptr<AppMode> mode;
};