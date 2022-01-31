#ifndef STATKI_BOARD_H
#define STATKI_BOARD_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Tile.h"

/// Klasa reprezentująca planszę o polach 10x10
class Board
{
protected:
    /// Tablica 10x10 pojedynczych pól planszy
    Tile tiles[10][10];
    /// Przesunięcie tablicy służące przy wyświetlaniu
    int offset;
    /// Zmienna przechowująca informacje czy to gracz czy komputer
    bool isPlayer;
public:
    /// Konstruktor 2 argumentowy klasy Board
    /// \param _offset
    /// \param _isPlayer
    Board(int _offset,bool _isPlayer=true);

    /// Funkcja rysująca planszę w oknie gry
    /// \param window Referencja do okna gry
    void Draw(sf::RenderWindow &window);

    /// Funkcja ustawiająca odpowiedni kolor polu, gdy jest ono kliknięte pierwszy raz podczas ustawiania przez gracza
    /// \param x Pozycja x kliknięta przez gracza
    /// \param y Pozycja x kliknięta przez gracza
    inline void SetHoovered(int x,int y)
    {
        tiles[x][y].SetHoovered();
    }

    /// Funkcja sprawdzająca czy pole jest zajęte przez statek
    /// \param x Pozycja x pola do sprawdzenia
    /// \param y Pozycja y pola do sprawdzenia
    /// \return Zwraca true, jeśli na polu jest statek
    inline bool IsBusy(int x,int y)
    {
        return tiles[x][y].IsTaken();
    }
};


#endif STATKI_BOARD_H