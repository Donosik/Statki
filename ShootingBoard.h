#ifndef STATKI_SHOOTINGBOARD_H
#define STATKI_SHOOTINGBOARD_H

#include "Board.h"

class ShootingBoard : public Board
{
public:
    ShootingBoard(bool _isPlayer=true);

    void Set(int x,int y) override;
};


#endif STATKI_SHOOTINGBOARD_H
