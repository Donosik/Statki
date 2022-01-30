#ifndef STATKI_SHOOTINGBOARD_H
#define STATKI_SHOOTINGBOARD_H

#include "Board.h"

class ShootingBoard : public Board
{
    int shootedCorrectly;
public:
    ShootingBoard(bool _isPlayer=true);

    bool Shoot(int x,int y,bool hit);
};


#endif STATKI_SHOOTINGBOARD_H
