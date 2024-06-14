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
    const int FRAME_DELAY = 1000 / FPS;         // 1/60 of a second (in miliseconds)
    const double UPDATE_INTERVAL = 1.0 / FPS;   // also 1/60 of a second (in seconds)

    //=======================================================================================================================================
    // UPDATE_INTERVAL is separated from FRAME_DELAY because of separating render and update.
    // Independent physics and graphics give the same physics update speed with different frame rates...
    // ...and thus a better feeling while playing the game.
    // With physics and graphics not separated the update will slow down when FPS drop or speed up when FPS rise.
    //=======================================================================================================================================

    // Define time counting variables
    Uint32 frameStart;
    Uint32 lastUpdate = SDL_GetTicks(); 
    int frameTime;                      // used to calculate time to wait at the end of the frame
    double accumulator = 0.0;           // used to count update loops
    double deltaTime = 0.0;

    // Main loop
    while(MagicMayhem.isRunning()) {
        // Get time at the start of a frame
        frameStart = SDL_GetTicks();

        // Handle events like keyboard inputs
        MagicMayhem.handleEvents();

        // Calculate deltaTime
        deltaTime = (SDL_GetTicks() - lastUpdate) / 1000.0;
        lastUpdate = SDL_GetTicks();
        accumulator += deltaTime;

        // Update based on UPDATE_INTERVAL (update is intependent from render)
        while(accumulator >= UPDATE_INTERVAL) {
            MagicMayhem.update(UPDATE_INTERVAL);
            accumulator -= UPDATE_INTERVAL;   
        } 

        // Render all objects on screen
        MagicMayhem.render();

        // Delay frame so it will be constant 60 FPS
        frameTime = SDL_GetTicks() - frameStart;
        if (FRAME_DELAY > lastUpdate) { SDL_Delay(FRAME_DELAY - frameTime); }
    }

    return EXIT_SUCCESS;
}