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

    // Define expected FPS and expectedFrameTime 
    const int FPS = 60;
    const double expectedFrameTime = 1000 / FPS; // 1/60 of a second

    // Define time counting variables
    Uint32 frameStart;
    Uint32 deltaTime;

    // Main loop
    while(MagicMayhem.isRunning()) {
        // Get time at the start of a frame
        frameStart = SDL_GetTicks();

        // Do all App stuff (handling events, updating and rendering of current AppMode)
        MagicMayhem.handleEvents();
        MagicMayhem.update();
        MagicMayhem.render();

        // Get time after rendering
        deltaTime = SDL_GetTicks() - frameStart;

        // Delay frame so it will be constant 60 FPS
        if (deltaTime < expectedFrameTime) { SDL_Delay(expectedFrameTime - deltaTime); }
    }

    return EXIT_SUCCESS;
}