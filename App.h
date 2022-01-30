#ifndef STATKI_APP_H
#define STATKI_APP_H

#include <SFML/Graphics.hpp>
#include "ShowingBoard.h"
#include "ShootingBoard.h"
#include <memory>

#include <iostream>

/// Główna klasa zarządzająca całą grą
class App
{
    /// Zmienna reprezentująca główne okno gry
    sf::RenderWindow window;
    std::unique_ptr<ShowingBoard> playerBoard;
    std::unique_ptr<ShootingBoard> playerShootingBoard;
    std::unique_ptr<ShowingBoard> computerBoard;
    std::unique_ptr<ShootingBoard> computerShootingBoard;
    /// Zmienna określająca, czy gracz jest w trybie ustawiania statków czy w trybie gry
    bool setting;
    /// Zmienna określająca przesunięcie jednej planszy od drugiej
    int offset;
    /// Tekst wyświetlany nad tablicą gracza
    sf::Text textPlayerBoard;
    /// Tekst wyświetlany nad tablicą, w która strzela gracz
    sf::Text textPlayerShootingBoard;
    /// Tekst wyświetlany jako komunikaty dla gracza podczas gry
    sf::Text comunicats;
    sf::Font font;
    bool isChoosen;
    int choosenX;
    int choosenY;
public:
    App();

    void Run();

    void Draw();

    void Events();
private:
    void Setting(sf::Event &event);

    void Shooting(sf::Event &event);

    void FontSetting();
};


#endif STATKI_APP_H
