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

    App& MagicMayhem = App::getInstance(); // Create new App called "MagicMayhem" (Yes, that's the title of this game)
    // Initialize SDL and App's window and renderer
    MagicMayhem.init("MAGIC MAYHEM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_ALLOW_HIGHDPI);

    // Define expected FPS, frame delay and game update interval 
    const int FPS = 60;                         // target FPS
    const int FRAME_DELAY = 1000 / FPS;         // 1/60 of a second (in miliseconds)
    const double UPDATE_INTERVAL = 1.0 / 60;    // also 1/60 of a second (in seconds)

    //======================================================================================================================//
    // UPDATE_INTERVAL is separated from FRAME_DELAY because of separating render and update.                               //
    // Independent physics and graphics give the same physics update speed with different frame rates and thus a better     //  
    // feeling while playing the game. With physics and graphics not separated the update will slow down when the FPS drop  //
    // or speed up when the FPS rise.                                                                                       //
    //======================================================================================================================//

    // Define time counting variables
    Uint32 frameStart;                  // stores time at the begining of each frame
    Uint32 lastUpdate = SDL_GetTicks(); // stores time of the last game update
    int frameTime;                      // used to calculate time to wait at the end of the frame
    double deltaTime = 0.0;             // used to count game update loops
    double accumulator = 0.0;           // used to count game update loops

    // Main application loop
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
        if (FRAME_DELAY > frameTime) { SDL_Delay(FRAME_DELAY - frameTime); }
    }

    return EXIT_SUCCESS; // "return 0;" but fancy lol
}