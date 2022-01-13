#include "App.h"

App::App() : window(sf::VideoMode(1200, 600), "Statki", sf::Style::Titlebar | sf::Style::Close), playerBoard(false), playerShootingBoard(true), computerBoard(false), computerShootingBoard(true),setting(true)
{
    Run();
}

#include <iostream>

void App::Run()
{
    while (window.isOpen())
    {
        try
        {
            Events();
        } catch (std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
            break;
        }
        Draw();
    }
}

void App::Events()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            // Faza ustawiania statków
            if (setting)
            {

            }
                // Faza strzelania
            else
            {

            }
        }
    }
}

void App::Draw()
{
    window.clear(sf::Color::Black);
    //playerBoard.Draw(window);
    //playerShootingBoard.Draw(window);
}