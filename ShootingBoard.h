#ifndef STATKI_SHOOTINGBOARD_H
#define STATKI_SHOOTINGBOARD_H

#include "Board.h"

/// Klasa reprezentująca tablicę do strzelania
class ShootingBoard : public Board
{
    /// Ile pól zostało ustrzelonych poprawnie
    int shootedCorrectly;
public:
    /// Konstruktor jednoparametrowy klasy
    /// \param _isPlayer Parametr określający czy plansza do strzelania jest gracza czy komputera
    ShootingBoard(bool _isPlayer=true);

    /// Funkcja strzelająca w dano pole
    /// \param x Pozycja x strzału
    /// \param y Pozycja y strzału
    /// \param hit Czy trafił strzał
    /// \return Zwraca true, gdy gracz trafił we wszystkie pola
    bool Shoot(int x,int y,bool hit);
};


#endif STATKI_SHOOTINGBOARD_H
