#pragma once // #pragma once

// include local headers
#include "./app_mode.hpp"

class Game : public AppMode {
 public:
    void handleEvents(SDL_Event event) override;
    void update() override;
    void render() override;
};
