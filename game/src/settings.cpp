// Include .hpp with the same name
#include "../include/settings.hpp"

// include c++ headers
#include <iostream>

// Include SDL2 headers
#include <SDL2/SDL.h>

// Include local headers
#include "../include/app.hpp"

void Settings::handleEvents(SDL_Event event) {
    switch (event.type) {
        // Add events to handle here
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_1:
                    std::cout << "Switching mode to MainMenu...\n";
                    App::getInstance().setMode(App::Mode::MainMenu);
                    break;
                case SDLK_2:
                    std::cout << "Switchin mode to Game...\n";
                    App::getInstance().setMode(App::Mode::Game);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void Settings::update() {

}

void Settings::render() {
    SDL_SetRenderDrawColor(App::getInstance().renderer, 0, 0, 255, 255);
}