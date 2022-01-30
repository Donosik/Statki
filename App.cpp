#include "App.h"

App::App() : window(sf::VideoMode(1250, 650), "Statki", sf::Style::Titlebar | sf::Style::Close)
{
    isChoosen = false;
    setting = true;
    // TODO: settingi zrobi
    playerBoard = std::make_unique<ShowingBoard>();
    playerShootingBoard = std::make_unique<ShootingBoard>();
    computerBoard = std::make_unique<ShowingBoard>();
    computerShootingBoard = std::make_unique<ShootingBoard>();

    FontSetting();

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
                Setting(event);
            }
                // Faza strzelania
            else
            {
                Shooting(event);
            }
        }
    }
}

void App::Draw()
{
    window.clear(sf::Color::Black);
    playerBoard->Draw(window);
    playerShootingBoard->Draw(window);
    window.draw(textPlayerBoard);
    window.draw(textPlayerShootingBoard);
    window.draw(comunicats);
    window.display();
}

#include <iostream>

void App::Setting(sf::Event &event)
{
    int xPos = event.mouseButton.x;
    int yPos = event.mouseButton.y;
    if (yPos < 50)
    {
        return;
    }
    if (xPos < 650)
    {
        return;
    }
    int x = (xPos - 650) / 60;
    int y = (yPos - 50) / 60;

    if (isChoosen)
    {
        isChoosen = false;
        playerBoard->SetHoovered(choosenX, choosenY);
        if (x == choosenX && y == choosenY)
        {
            return;
        }
        if (x == choosenX)
        {
            if (abs(y - choosenY) <= 4 && abs(y - choosenY) > 0)
            {
                for (int i = std::min(y, choosenY); i <= std::max(y, choosenY); i++)
                {
                    if (playerBoard->IsBusy(x, i))
                    {
                        return;
                    }
                }
                playerBoard->SetShip(x, y, x, choosenY);
            }
        }
        if (y == choosenY)
        {
            if (abs(x - choosenX) <= 4 && abs(x - choosenY) > 0)
            {
                for (int i = std::min(x, choosenX); i <= std::max(x, choosenX); i++)
                {
                    if (playerBoard->IsBusy(i, y))
                    {
                        return;
                    }
                }
                playerBoard->SetShip(x, y, choosenX, y);
            }
        }

    }
    else
    {
        isChoosen = true;
        choosenX = x;
        choosenY = y;
        //TODO: Nie działa sprawdzić czemu, niepoprawnie sprawdza czy pole jest zajete
        if (playerBoard->IsBusy(choosenX, choosenX))
        {
            std::cout << "JEST ZAJETE" << std::endl;
            isChoosen = false;
            return;
        }
        playerBoard->SetHoovered(choosenX, choosenY);
    }

}

void App::Shooting(sf::Event &event)
{

}

void App::FontSetting()
{
    if (!font.loadFromFile("arial.ttf"))
    {
        throw std::exception("Error with loading font from file");
    }
    textPlayerBoard.setFont(font);
    textPlayerShootingBoard.setFont(font);
    comunicats.setFont(font);

    textPlayerBoard.setString("Tablica Gracza");
    textPlayerShootingBoard.setString("Tablica do strzelania");
    comunicats.setString("");

    textPlayerBoard.setCharacterSize(30);
    textPlayerShootingBoard.setCharacterSize(30);
    comunicats.setCharacterSize(30);

    textPlayerBoard.setFillColor(sf::Color::Red);
    textPlayerShootingBoard.setFillColor(sf::Color::Red);
    comunicats.setFillColor(sf::Color::Red);

    //textPlayerBoard.setStyle(sf::Text::Bold);
    //textPlayerShootingBoard.setStyle(sf::Text::Bold);

    textPlayerBoard.setPosition(850, 0);
    textPlayerShootingBoard.setPosition(150, 0);
    comunicats.setPosition(400, 150);
}