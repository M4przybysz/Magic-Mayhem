#pragma once // #pragma once

// include std c++ libraries

// Include SDL2 libraries

// include local libraries

//! NOTE: Later, put MainMenu, Game and Settings in spearate files
//! Current structure of this file is temporary

// Virtual class that is a blueprint for all App modes
class AppMode {
 public:
    virtual ~AppMode() {}
    virtual void handleEvents() {}
    virtual void update() {}
    virtual void render() {}
};

// Class for applications main menu
class MainMenu : public AppMode {
 public:
    void handleEvents() override {}
    void update() override {}
    void render() override {}
};

// Class for an actual game
class Game : public AppMode {
 public:
    void handleEvents() override {}
    void update() override {}
    void render() override {}
};

// Class for application and game settings
class Settings : public AppMode {
 public:
    void handleEvents() override {}
    void update() override {}
    void render() override {}
};