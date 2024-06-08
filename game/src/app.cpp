// Include .hpp with the same name
#include "../include/app.hpp"

// Include std c++ libraries

// Include SDL libraries

// Include local libraries

App::App() { std::cout << "App created!\n"; }
App::~App() { std::cout << "App destroyed!\n"; }

void App::init(const char* title, int x, int y, int width, int height, Uint32 flags) {

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL initialized...\n";

        window_ = SDL_CreateWindow(title, x, y, width, height, flags);
        if(window_) { std::cout << "Window created...\n"; }
        else { std::cerr << "Problems while creating a window!\n"; }

        renderer = SDL_CreateRenderer(window_, 1, 0);
        if(renderer) { std::cout << "Renderer created...\n"; }
        else { std::cerr << "Problems while creating a renderer!\n"; }

        isRunning_ = true;
        std::cout << "Magic Mayhem is running!!!\n";
    }
    else {
        std::cerr << "Problems while initializing SDL!\n";
        isRunning_ = false;
    }

}


void App::handleEvents() {

}

void App::update() {

}

void App::render() {

}

void App::cleanSDL() {
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}