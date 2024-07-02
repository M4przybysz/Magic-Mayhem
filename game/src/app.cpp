// Local Headers
#include "../include/App.hpp"

SDL_Renderer* App::renderer = nullptr;

App::App() { 
    std::clog << "App created!\n";

    currentMode_ = Mode::MainMenu;
    mode = std::make_unique<MainMenu>();
    std::clog << "App is running in MainMenu (default) mode...\n"; 
}

App::~App() { 
    SDL_DestroyWindow(window_);
    std::clog << "Window destroyed...\n";
    SDL_DestroyRenderer(renderer);
    std::clog << "Renderer destroyed...\n";
    SDL_Quit();
    std::clog << "SDL quitted...\n";
    std::clog << "App destroyed!\n"; 
}

void App::setMode(Mode newMode) {
    currentMode_ = newMode;
    switch (newMode) {
        case Mode::MainMenu:
            std::clog << "Current AppMode: MainMenu\n";
            mode = std::make_unique<MainMenu>();
            break;
        case Mode::Game:
            std::clog << "Current AppMode: Game\n";
            mode = std::make_unique<Game>();
            break;
        case Mode::Settings:
            std::clog << "Current AppMode: Settings\n";
            mode = std::make_unique<Settings>();
            break;
        default:
            break;
    }
}

void App::init(const std::string& title, const int& x, const int& y, const int& width, const int& height, const unsigned int& flags) {
    // Init all SDL shit or it won't work
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) { // App needs SDL initialized to do anything
        std::clog << "SDL initialized...\n";
        window_ = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);

        if(window_) { // App needs a window_ to create renderer
            std::clog << "Window created...\n"; 
            renderer = SDL_CreateRenderer(window_, 1, 0);

            if(renderer) { // App needs a renderer to display anything
                std::clog << "Renderer created...\n";
                SDL_SetRenderDrawColor(renderer, 127, 0, 255, 255);
                isRunning_ = true;
                std::clog << "Magic Mayhem is running!!!\n";
            }
            else { std::cerr << "Couldn't create a renderer!\n"; }
        }
        else { std::cerr << "Couldn't create a window!\n"; }
    }
    else {
        std::cerr << "Couldn't initialize SDL!\n";
        isRunning_ = false;
    }
}

void App::handleEvents() {
    //! Since in one frame we can have multiple events happening the section below needs to be changed into a loop that...
    //! ... will take and handle all (or most) events in one frame.

    SDL_Event event; // variable to store events
    SDL_PollEvent(&event); // get new event

    // Handle basic App events
    switch(event.type) {
        case SDL_QUIT: // Close a window.
            isRunning_ = false;
            std::clog << "Window closed...\n";
            break;
        
        // >>>Add more events to be handled here<<<

        default:
            break;
    }

    mode->handleEvents(event); // Handle events for specific App mode
}

void App::update(const double& deltaTime) {
    mode->update(deltaTime); // "No shit, Sherlock." It looks funny
}

void App::render() {
    SDL_RenderClear(renderer);      // Clear renderer to show new things on screen

    // >>> Add stuff to render here <<<
    mode->render();

    SDL_RenderPresent(renderer);    // Show everything on screen
}
