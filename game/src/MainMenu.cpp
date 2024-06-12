// Local Headers
#include "../include/App.hpp"
#include "../include/MainMenu.hpp"

// SDL2 Headers
#include <SDL2/SDL.h>

// Local Headers
#include <iostream>


void MainMenu::handleEvents(SDL_Event event) {
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_2:
                    std::clog << "Switching mode to Game...\n";
                    App::getInstance().setMode(App::Mode::Game);
                    break;
                case SDLK_3:
                    std::clog << "Switchin mode to Settings...\n";
                    App::getInstance().setMode(App::Mode::Settings);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void MainMenu::update() {

}

void MainMenu::render() {
    SDL_SetRenderDrawColor(App::getInstance().renderer, 255, 0, 0, 255);
}
