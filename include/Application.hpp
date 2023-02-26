#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include <string>
#include "Globals.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Application
{
public:
    Application();
    virtual ~Application();

    // Public Functions
    void run();

private:
    // Variables
    float delta_time;
    unsigned int width;
    unsigned int height;
    unsigned int bits;
    unsigned int framerate;

    // Init
    void init_vars();
    void init_window(unsigned int w, unsigned int h, unsigned int b);

    // Memory
    void free();

    // Update
    void update(const float& dt);
    void update_dt();
    void update_events();

    // Render
    void render();

    // Objects
    sf::VideoMode vid_mode;
    sf::Event w_event;
    sf::RenderWindow* window;
    sf::Clock clock;
};

#endif