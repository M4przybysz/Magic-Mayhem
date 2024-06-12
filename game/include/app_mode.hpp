#pragma once // #pragma once

// Include SDL2 libraries
#include <SDL2/SDL.h>

// Virtual class that is a blueprint for all App modes
// App modes: MainMenu, Game, Settings
class AppMode {
 public:
    virtual ~AppMode() {}
    virtual void handleEvents(SDL_Event event) {}
    virtual void update() {}
    virtual void render() {}
};