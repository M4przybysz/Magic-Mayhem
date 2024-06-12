// Local Headers
#include "../include/App.hpp"
#include "../include/Settings.hpp"

// SDL Headers
#include <SDL2/SDL.h>

// C++ Headers
#include <iostream>


void Settings::handleEvents(SDL_Event event) {
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_1:
                    std::clog << "Switching mode to MainMenu...\n";
                    App::getInstance().setMode(App::Mode::MainMenu);
                    break;
                case SDLK_2:
                    std::clog << "Switchin mode to Game...\n";
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
