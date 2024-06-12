// Include c++ headers

// Include SDL2 headers

// Include local headers
#include "./include/app.hpp"
#include "./include/CardReader.hpp"

int main(int argc, char *argv[]) {
    std::shared_ptr<CardReader> reader = std::make_shared<CardReader>(CardReader());

    reader->openFile("./cards.list");

    if(!reader->isFileOpen()) {
        std::cerr << "Error: File not opened!\n";
        return 1;
    }
    else {
        std::clog << "File opened successfully!\n";
    }
    reader->processFile();

    // Create new App called "MagicMayhem" (Yes, that's the title of this game)
    App& MagicMayhem = App::getInstance();

    // Initialize SDL and App's window and renderer
    MagicMayhem.init("MAGIC MAYHEM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_ALLOW_HIGHDPI);

    // Main loop
    while(MagicMayhem.isRunning()) {
        MagicMayhem.handleEvents();
        MagicMayhem.update();
        MagicMayhem.render();
    }
    
    // Clear memory (mostly SDL pointers that are not smart)
    MagicMayhem.clean();

    return EXIT_SUCCESS;
}