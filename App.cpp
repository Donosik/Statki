#include "App.h"

App::App() : window(sf::VideoMode(1250, 650), "Statki", sf::Style::Titlebar | sf::Style::Close)
{
    isChoosen = false;
    setting = true;
    playerBoard = std::make_unique<ShowingBoard>();
    playerShootingBoard = std::make_unique<ShootingBoard>();
    computerBoard = std::make_unique<ShowingBoard>(false);
    computerShootingBoard = std::make_unique<ShootingBoard>(false);
    shipsSetted[0] = false;
    shipsSetted[1] = false;
    shipsSetted[2] = false;
    shipsSetted[3] = false;

    FontSetting();

    Run();
}

void App::Run()
{
    while (window.isOpen())
    {
        try
        {
            Events();
        } catch (std::exception &ex)
        {
            throw ex;
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
                bool endSetting = true;
                for (int i = 0; i < 4; i++)
                {
                    if (shipsSetted[i] == false)
                    {
                        endSetting = false;
                    }
                }
                if (endSetting)
                {
                    setting = false;
                }

            }
                // Faza strzelania
            else
            {
                try
                {
                    PlayerShooting(event);
                    ComputerShooting(event);
                }
                catch (std::exception &ex)
                {
                    if ((std::string) ex.what() == "graczWin")
                    {
                        comunicats.setString("Gracz Wygral");
                    }
                    else if ((std::string) ex.what() == "computerWin")
                    {
                        comunicats.setString("Komputer Wygral");
                    }
                }
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
                if (!shipsSetted[abs(y - choosenY) - 1])
                {
                    playerBoard->SetShip(x, y, x, choosenY);
                    shipsSetted[abs(y - choosenY) - 1] = true;
                }
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
                if (!shipsSetted[abs(x - choosenX) - 1])
                {
                    playerBoard->SetShip(x, y, choosenX, y);
                    shipsSetted[abs(x - choosenX) - 1] = true;
                }
            }
        }

    }
    else
    {
        isChoosen = true;
        choosenX = x;
        choosenY = y;

        if (playerBoard->IsBusy(choosenX, choosenY))
        {
            isChoosen = false;
            return;
        }

        playerBoard->SetHoovered(choosenX, choosenY);
    }

}

void App::PlayerShooting(sf::Event &event)
{
    int xPos = event.mouseButton.x;
    int yPos = event.mouseButton.y;
    if (yPos < 50)
    {
        return;
    }
    if (xPos > 650)
    {
        return;
    }
    int x = (xPos) / 60;
    int y = (yPos - 50) / 60;

    if (computerBoard->IsBusy(x, y))
    {
        if (playerShootingBoard->Shoot(x, y, true))
        {
            throw std::exception("graczWin");
        }
    }
    else
    {
        playerShootingBoard->Shoot(x, y, false);
    }


}

void App::ComputerShooting(sf::Event &event)
{
    int x = 0;
    int y = 0;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<std::mt19937::result_type> dist;

    do
    {
        x = dist(gen) % 10;
        y = dist(gen) % 10;

    } while (playerBoard->isShooted(x, y));

    std::cout<<x<<","<<y<<std::endl;

    if (playerBoard->IsBusy(x, y))
    {
        playerBoard->SetShooted(x,y,true);
        if (computerShootingBoard->Shoot(x, y, true))
        {
            throw std::exception("computerWin");
        }
    }
    else
    {
        playerBoard->SetShooted(x,y,false);
        computerShootingBoard->Shoot(x, y, false);
    }
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

    textPlayerBoard.setPosition(850, 0);
    textPlayerShootingBoard.setPosition(150, 0);
    comunicats.setPosition(400, 150);
}