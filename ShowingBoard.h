#ifndef STATKI_SHOWINGBOARD_H
#define STATKI_SHOWINGBOARD_H

#include "Board.h"

/// Klasa dziedzicząca po Board, reprezentuje tablicę z ustawionymi na niej statkami
class ShowingBoard : public Board
{
public:
    /// Konstruktor jednoargumentowy klasy ShowingBoard
    /// \param _isPlayer Czy dana tablica jest gracza, czy komputera
    ShowingBoard(bool _isPlayer = true);

    /// Funkcja ustawiająca Statek na podanych polach
    /// \param xPos1 Pozycja x jednego rogu statku
    /// \param yPos1 Pozycja y jednego rogu statku
    /// \param xPos2 Pozycja x drugiego rogu statku
    /// \param yPos2 Pozycja y drugiego rogu statku
    void SetShip(int xPos1, int yPos1, int xPos2, int yPos2);

    /// Czy dane pole jest statkiem
    /// \param x Pozycja x potencjalnego statku
    /// \param y Pozycja y potencjalnego statku
    /// \return Zwraca true, gdy pod danymi koordynatami jest statek
    bool IsShip(int x, int y);

    /// Czy w dane pole było już strzelone
    /// \param x Pozycja x strzału
    /// \param y Pozycja y strzału
    /// \return Zwraca true, gdy w pole było już strzelone
    bool isShooted(int x, int y);

    /// Strzela w dane pole
    /// \param x Pozycja x strzału
    /// \param y Pozycja y strzału
    /// \param hit Czy trafiło w statek czy nie
    void SetShooted(int x, int y, bool hit);

private:
    /// Ustawia statki na stałych polach, gdy jest to pole komputera
    void SetShipsAsComputer();
};


#endif STATKI_SHOWINGBOARD_H
