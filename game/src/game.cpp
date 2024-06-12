// Include .hpp with the same name
#include "../include/game.hpp"

// include c++ headers
#include <iostream>

// Include SDL2 headers
#include <SDL2/SDL.h>

// Include local headers
#include "../include/app.hpp"

void Game::handleEvents(SDL_Event event) {
    switch (event.type) {
        // Add events to handle here
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_1:
                    std::cout << "Switching mode to MainMenu...\n";
                    App::getInstance().setMode(App::Mode::MainMenu);
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

void Game::update() {

}

void Game::render() {
    SDL_SetRenderDrawColor(App::getInstance().renderer, 0, 255, 0, 255);
}