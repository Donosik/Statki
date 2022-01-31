#ifndef STATKI_TILE_H
#define STATKI_TILE_H

#include <SFML/Graphics.hpp>

/// Klasa określająca pojedyncze pole na planszy
class Tile
{
    /// Enum określający czy na polu jest statek, czy nie
    enum class StatusShip
    {
        EMPTY,
        TAKEN
    };

    /// Enum określajacy czy w dane pole ktoś już strzelił czy nie
    enum class StatusShoot
    {
        EMPTY,
        SHOOTED
    };
    /// Zmienna określająca kształt obiektu
    sf::RectangleShape shape;
    /// Rozmiar obiektu
    float size;
    /// Pozycja x pola
    int xPos;
    /// Pozycja y pola
    int yPos;
    /// Skala pola, by określić przerwy
    float scale;
    /// Stan statku na polu
    StatusShip statusShip;
    /// Stan strzału na polu
    StatusShoot statusShoot;
public:
    /// Konstruktor bezargumentowy klasy
    Tile();

    /// Konstruktor trójargumentowy klasy
    /// \param x Pozycja x pola
    /// \param y Pozycja y pola
    /// \param offset Przesunięcie pola
    Tile(int x, int y, int offset);

    /// Funkcja rysująca pole
    /// \param window Referencja do głównego okna aplikacji
    void Draw(sf::RenderWindow &window);

    /// UStawia status pola na konkretny statek
    /// \param type Zmienna określająca jaki statek jest na polu
    void SetStatus(int type);

    /// Ustawia stan pola na kliknięty tylko raz podczas ustawiania
    void SetHoovered();

    /// Funkcja sprawdza czy pole jest zajęte przez statek
    /// \return Zwraca true, gdy na polu jest już statek
    bool IsTaken();

    /// Funkcja ustawia, że w pole już strzelono
    /// \param hit Czy trafiono w statek
    void SetShooted(bool hit);

    /// Funkcja zwraca, czy w pole już strzelono
    /// \return Zwraca true, gdy w pole już strzelono
    bool IsShooted();
};


#endif STATKI_TILE_H
