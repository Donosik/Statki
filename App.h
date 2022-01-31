#ifndef STATKI_APP_H
#define STATKI_APP_H

#include <SFML/Graphics.hpp>
#include "ShowingBoard.h"
#include "ShootingBoard.h"
#include <memory>
#include <random>
#include <chrono>
#include <iostream>

/// Główna klasa zarządzająca całą grą
class App
{
    /// Zmienna reprezentująca główne okno gry
    sf::RenderWindow window;
    /// Wskaźnik na plansze ze statkami gracza
    std::unique_ptr<ShowingBoard> playerBoard;
    /// Wskaźnik na planszę do strzelania gracza
    std::unique_ptr<ShootingBoard> playerShootingBoard;
    /// Wskaźnik na planszę ze statkami komputera
    std::unique_ptr<ShowingBoard> computerBoard;
    /// Wskaźnik na planszę do strzelania komputera
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
    /// Zmienna przechowująca wczytaną czcionkę
    sf::Font font;
    /// Czy pole do ustawienia statku jest wybrane
    bool isChoosen;
    /// Koordynat X wybranego pola
    int choosenX;
    /// Koordynat Y wybranego pola
    int choosenY;
    /// Tablica pamietająca jakie statki zostały już ustawione przez gracza
    bool shipsSetted[4];
public:
    /// Konstruktor bezargumentowy klasy App
    App();

    /// Funkcja będąca główną pętlą gry
    void Run();

    /// Funkcja odpowiadająca za rysowanie wszystkich elementów gry
    void Draw();

    /// Funkcja obługująca wszystkie zdarzenia podczas gry
    void Events();

private:
    /// Funkcja odpowiadająca za odpowiednie ustawienie Statków przez gracza
    /// \param event Referencja do wszystkich zdarzeń przechwyconych przez okno
    void Setting(sf::Event &event);

    /// Funkcja kontrolująca strzelanie do statków komputera przez gracza
    /// \param event Referencja do wszystkich zdarzeń przechwyconych przez okno
    void PlayerShooting(sf::Event &event);

    /// Funkcja kontrolująca strzelanie do statków gracza przez komputer
    /// \param event Referencja do wszystkich zdarzeń przechwyconych przez okno
    void ComputerShooting(sf::Event &event);

    /// Funkcja ustawiająca wszystkie rzeczy związane z tekstami i czcionkami
    void FontSetting();
};


#endif STATKI_APP_H
