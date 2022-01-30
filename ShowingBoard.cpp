#include "ShowingBoard.h"

ShowingBoard::ShowingBoard(bool _isPlayer) : Board(650, _isPlayer)
{
    if (_isPlayer == false)
    {
        SetShipsAsComputer();
    }
}

void ShowingBoard::SetShip(int xPos1, int yPos1, int xPos2, int yPos2)
{
    int dlugosc = 0;
    if (xPos1 == xPos2)
    {
        dlugosc = abs(yPos1 - yPos2);
        if (yPos1 > yPos2)
        {
            for (int i = yPos2; i <= yPos1; i++)
            {
                tiles[xPos1][i].SetStatus(dlugosc);
            }
        }
        if (yPos2 > yPos1)
        {
            for (int i = yPos1; i <= yPos2; i++)
            {
                tiles[xPos1][i].SetStatus(dlugosc);
            }
        }
    }
    else if (yPos1 == yPos2)
    {
        dlugosc = abs(xPos1 - xPos2);
        if (xPos1 > xPos2)
        {
            for (int i = xPos2; i <= xPos1; i++)
            {
                tiles[i][yPos1].SetStatus(dlugosc);
            }
        }
        if (xPos2 > xPos1)
        {
            for (int i = xPos1; i <= xPos2; i++)
            {
                tiles[i][yPos1].SetStatus(dlugosc);
            }
        }
    }
}

bool ShowingBoard::IsShip(int x, int y)
{
    return tiles[x][y].IsTaken();
}

void ShowingBoard::SetShipsAsComputer()
{
    SetShip(0,0,0,4);
    SetShip(1,0,1,3);
    SetShip(2,0,2,2);
    SetShip(3,0,3,1);
}

bool ShowingBoard::isShooted(int x, int y)
{
    return tiles[x][y].IsShooted();
}

void ShowingBoard::SetShooted(int x, int y,bool hit)
{
    tiles[x][y].SetShooted(hit);
}