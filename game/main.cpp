// Include std c++ libraries

// Include SDL2 libraries

// Include local libraries
#include "./include/app.hpp"

int main(int argc, char *argv[]) {
    // Create new App called "MagicMayhem"
    std::unique_ptr<App> MagicMayhem = std::make_unique<App>();

    MagicMayhem->init("MAGIC MAYHEM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_ALLOW_HIGHDPI);

    while(MagicMayhem->isRunning()) {
        MagicMayhem->handleEvents();
        MagicMayhem->update();
        MagicMayhem->render();
    }

    MagicMayhem->cleanSDL();

    return EXIT_SUCCESS;
}