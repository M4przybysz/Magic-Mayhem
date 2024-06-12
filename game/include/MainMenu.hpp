#pragma once 

// Local Headers
#include "./AppMode.hpp"

class MainMenu : public AppMode {
 public:
    void handleEvents(SDL_Event event) override;
    void update() override;
    void render() override;
};
