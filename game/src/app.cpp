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
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::clog << "SDL initialized...\n";

        // App needs SDL initialized to do anything
        window_ = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);
        if(window_) { 
            std::clog << "Window created...\n"; 
            
            // App needs a window_ to create renderer
            renderer = SDL_CreateRenderer(window_, 1, 0);
            if(renderer) { 
                std::clog << "Renderer created...\n";
                SDL_SetRenderDrawColor(renderer, 127, 0, 255, 255);

                // App needs a renderer to display everything
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
    // Get new event
    SDL_Event event;
    SDL_PollEvent(&event);

    // Handle basic App events
    switch(event.type) {
        case SDL_QUIT: // Close a window.
            isRunning_ = false;
            std::clog << "Window closed...\n";
            break;
        
        // Add more events to be handled here

        default:
            break;
    }

    // Handle events for specific App mode
    mode->handleEvents(event);
}

void App::update(const double& deltaTime) {
    mode->update(deltaTime); // "No shit, Sherlock." It looks funny
}

void App::render() {
    // Clear renderer to show new things on screen
    SDL_RenderClear(renderer);

    // Add stuff to render here
    mode->render();

    // Show things on screen
    SDL_RenderPresent(renderer);
}
