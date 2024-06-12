// Include .hpp with the same name
#include "../include/main_menu.hpp"

// include c++ headers
#include <iostream>

// Include SDL2 headers
#include <SDL2/SDL.h>

// Include local headers
#include "../include/app.hpp"

void MainMenu::handleEvents(SDL_Event event) {
    switch (event.type) {
        // Add events to handle here
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_2:
                    std::cout << "Switching mode to Game...\n";
                    App::getInstance().setMode(App::Mode::Game);
                    break;
                case SDLK_3:
                    std::cout << "Switchin mode to Settings...\n";
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