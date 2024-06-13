// Local Headers
#include "./include/App.hpp"
#include "./include/CardReader.hpp"

// SDL Headers

// C++ Headers

int main(int argc, char *argv[]) {
    // Create new File reader responsible for reading cards data from cards.list file
    std::shared_ptr<CardReader> reader = std::make_shared<CardReader>(CardReader());

    reader->openFile("./cards.list");

    if(!reader->isFileOpen()) {
        std::cerr << "Error: File not opened!\n";
        return 1;
    }
    else { std::clog << "File opened successfully!\n"; }

    reader->processFile(); // Read all cards data

    // Create new App called "MagicMayhem" (Yes, that's the title of this game)
    App& MagicMayhem = App::getInstance();

    // Initialize SDL and App's window and renderer
    MagicMayhem.init("MAGIC MAYHEM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_ALLOW_HIGHDPI);

    // Define expected FPS and FRAME_DELAY 
    const int FPS = 60;
    const int FRAME_DELAY = 1000 / FPS; // 1/60 of a second
    const double PHYSICS_UPDATE_INTERVAL = 1000 / FPS; // also 1/60 of a second

    // Define time counting variables
    Uint32 frameStart;
    int frameTime;
    double accumulator = 0.0;
    double deltaTime = 0.0;

    // Main loop
    while(MagicMayhem.isRunning()) {
        // Get time at the start of a frame
        frameStart = SDL_GetTicks();

        // Handle events like keyboard inputs
        MagicMayhem.handleEvents();

        // Update game physics in regular intervals (update intependent from render)
        deltaTime = (SDL_GetTicks() - frameStart) / 1000.0;
        accumulator += deltaTime;
        while(accumulator >= PHYSICS_UPDATE_INTERVAL) {
            MagicMayhem.update(PHYSICS_UPDATE_INTERVAL);
            accumulator -= PHYSICS_UPDATE_INTERVAL;   
        }

        // Render all objects on screen
        MagicMayhem.render();

        // Delay frame so it will be constant 60 FPS
        frameTime = SDL_GetTicks() - frameStart;
        if (FRAME_DELAY > frameTime) { SDL_Delay(FRAME_DELAY - frameTime); }
    }

    return EXIT_SUCCESS;
}