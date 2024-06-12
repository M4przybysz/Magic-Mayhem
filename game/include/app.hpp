#pragma once

// Local Headers
#include "./Game.hpp"
#include "./MainMenu.hpp"
#include "./Settings.hpp"

// SDL Headers
#include <SDL2/SDL.h>

// C++ Headers
#include <iostream>
#include <memory>
#include <string>

class App {
 public:
    App();
    ~App();

    // Enum class with all application modes
    enum class Mode { 
        MainMenu = 0, 
        Game = 1, 
        Settings = 2
    };

    void setMode(Mode newMode); 

    // Basicaly return self?
    static App& getInstance() {
        static App instance;
        return instance;
    }

    void init(const std::string& title, const int& x, const int& y, const int& width, const int& height, const unsigned int& flags); // move to constructor
    bool isRunning() { return isRunning_; };
    
    void handleEvents();
    void update();
    void render();

    static SDL_Renderer* renderer;

 private:
    bool isRunning_ = false;
    SDL_Window* window_;
    Mode currentMode_;
    std::unique_ptr<AppMode> mode;
};
