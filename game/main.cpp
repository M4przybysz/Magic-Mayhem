// Include std c++ libraries

// Include SDL2 libraries

// Include local libraries
#include "./include/app.hpp"

int main(int argc, char *argv[]) {
    // Create new App called "MagicMayhem"
    std::unique_ptr<App> MagicMayhem = std::make_unique<App>();

    // Initialize SDL and App's window and renderer
    MagicMayhem->init("MAGIC MAYHEM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_ALLOW_HIGHDPI);

    // Main loop
    while(MagicMayhem->isRunning()) {
        MagicMayhem->handleEvents();
        MagicMayhem->update();
        MagicMayhem->render();
    }

    // Clear memory (mostly SDL pointers that are not smart)
    MagicMayhem->clean();

    return EXIT_SUCCESS;
}