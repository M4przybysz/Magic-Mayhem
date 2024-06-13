// Local Headers
#include "../include/App.hpp"
#include "../include/Game.hpp"

// SDL Headers
#include <SDL2/SDL.h>

// C++ Headers
#include <iostream>

void Game::handleEvents(SDL_Event event) {
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_1:
                    std::clog << "Switching mode to MainMenu...\n";
                    App::getInstance().setMode(App::Mode::MainMenu);
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

void Game::update() {

}

void Game::render() {
    SDL_SetRenderDrawColor(App::getInstance().renderer, 0, 255, 0, 255);
}