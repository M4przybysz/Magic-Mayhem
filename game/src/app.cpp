// Include .hpp with the same name
#include "../include/app.hpp"

// Include std c++ libraries

// Include SDL libraries

// Include local libraries

SDL_Renderer* App::renderer = nullptr;

App::App() { 
    std::cout << "App created!\n";

    // Set default App mode
    currentMode_ = Mode::MainMenu;
    mode = std::make_unique<MainMenu>();
    std::cout << "App is running in MainMenu (default) mode...\n"; 
}
App::~App() { std::cout << "App destroyed!\n"; }

void App::setMode(Mode newMode) {
    currentMode_ = newMode;
    switch (newMode) {
        case Mode::MainMenu:
            mode = std::make_unique<MainMenu>();
            break;
        case Mode::Game:
            mode = std::make_unique<Game>();
            break;
        case Mode::Settings:
            mode = std::make_unique<Settings>();
            break;
        default:
            break;
    }
}


void App::init(const char* title, int x, int y, int width, int height, Uint32 flags) {

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL initialized...\n";

        window_ = SDL_CreateWindow(title, x, y, width, height, flags);
        if(window_) { std::cout << "Window created...\n"; }
        else { std::cerr << "Couldn't create a window!\n"; }

        renderer = SDL_CreateRenderer(window_, 1, 0);
        if(renderer) { 
            std::cout << "Renderer created...\n";
            SDL_SetRenderDrawColor(renderer, 127, 0, 255, 255);
        }
        else { std::cerr << "Couldn't create a renderer!\n"; }

        isRunning_ = true;
        std::cout << "Magic Mayhem is running!!!\n";
    }
    else {
        std::cerr << "Couldn't initialize SDL!\n";
        isRunning_ = false;
    }

}

void App::handleEvents() {
    mode->handleEvents();

    //! NOTE: Make separate event handling for all modes or try to somehow combine them
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type) {
        case SDL_QUIT: // Close a window.
            isRunning_ = false;
            std::cout << "Window closed...\n";
            break;
        
        // Add more events to handle here

        default:
            break;
    }
}

void App::update() {
    mode->update();
}

void App::render() {
    mode->render();

    //! NOtE: Put code below in all render methods or "mode->render()" in the middle 
    SDL_RenderClear(renderer);

    // Add stuff to render here

    SDL_RenderPresent(renderer);
}

void App::clean() {
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}