#include "ShootingBoard.h"

ShootingBoard::ShootingBoard(bool _isPlayer) : Board(0, _isPlayer)
{
    shootedCorrectly=0;
}

bool ShootingBoard::Shoot(int x, int y,bool hit)
{
    tiles[x][y].SetShooted(hit);
    if(hit)
    {
        shootedCorrectly++;
    }
    if(shootedCorrectly==14)
    {
        return true;
    }
    else
    {
        return false;
    }
}