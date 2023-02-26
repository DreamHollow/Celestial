#include "Application.hpp"

Application::Application()
{
    init_vars();
    init_window(800,600,32);
}

Application::~Application()
{
    free();
}

void Application::init_vars()
{
    if(verbose)
    {
        std::cout << "Verbose output is enabled." << "\n";
        std::cout << "Initializing application variables..." << "\n";
    }

    window = nullptr;
    delta_time = 0.f;
    framerate = 60;

    // Defaults
    // width = 800;
    // height = 600;

    if(verbose)
    {
        std::cout << "Variables initialized." << "\n";
    }
}

void Application::init_window(unsigned int w, unsigned int h, unsigned int b)
{
    if(verbose)
    {
        std::cout << "Initializing window parameters..." << "\n";
    }

    // These variables exist for configuration purposes

    this->width = w;
    this->height = h;
    this->bits = b;

    vid_mode.width = width;
    vid_mode.height = height;
    vid_mode.bitsPerPixel = bits;

    try
    {
        if(!vid_mode.isValid())
        {
            std::cout << "Error, unable to initialize window!" << "\n";

            free(); // Force memory to free

            throw "Unable to validate window.";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }

    this->window = new sf::RenderWindow(vid_mode, "Test", sf::Style::Close);
    // Do math here to always get relative screen center
    window->setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 3.5, sf::VideoMode::getDesktopMode().height / 4));
    window->setFramerateLimit(framerate);

    if(debug)
    {
        std::cout << db_string << "Window reset position to ";
        std::cout << (sf::VideoMode::getDesktopMode().width / 3.5) << ", ";
        std::cout << (sf::VideoMode::getDesktopMode().height / 4) << ".\n";

        std::cout << db_string << "Framerate set to " << framerate << ".\n";
    }

    if(verbose)
    {
        std::cout << "Window initialized." << "\n";
    }
}

void Application::free()
{
    delete this->window;

    if(debug && window == nullptr)
    {
        std::cout << db_string << "Window was nullptr; window was freed." << "\n";
    }

    if(debug && window != nullptr)
    {
        std::cout << db_string << "Window was freed." << "\n";
    }
}

void Application::update(const float &dt)
{
    update_events();
}

void Application::update_dt()
{
    delta_time = clock.restart().asSeconds();
}

void Application::update_events()
{
    while(window->pollEvent(w_event))
    {
        switch(w_event.type)
        {
            case sf::Event::Closed:
            {
                this->window->close();
                if(verbose)
                {
                    std::cout << "Window closed by user." << "\n";
                }
                break;
            }
        }
    }
}

void Application::render()
{
    window->clear();

    // Render Window Items

    window->display();
}

void Application::run()
{
    if(verbose)
    {
        std::cout << "Starting main loop..." << "\n";
    }

    while(window->isOpen())
    {
        update_dt();
        update(delta_time);
        render();
    }

    if(verbose)
    {
        std::cout << "Exiting program loop..." << "\n";
    }
}