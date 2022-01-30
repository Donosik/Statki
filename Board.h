#ifndef STATKI_BOARD_H
#define STATKI_BOARD_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Tile.h"

class Board
{
protected:
    bool isDead;
    Tile tiles[10][10];
    int offset;
    bool isPlayer;
public:
    Board(int _offset,bool _isPlayer=true);

    void Draw(sf::RenderWindow &window);

    inline void SetHoovered(int x,int y)
    {
        tiles[x][y].SetHoovered();
    }

    inline bool getIsDead()
    {
        return isDead;
    }

    inline bool IsBusy(int x,int y)
    {
        return tiles[x][y].IsTaken();
    }
};


#endif STATKI_BOARD_H