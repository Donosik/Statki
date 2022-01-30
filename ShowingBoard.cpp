#include "ShowingBoard.h"

ShowingBoard::ShowingBoard(bool _isPlayer) : Board(650, _isPlayer)
{

}

void ShowingBoard::Set(int x, int y)
{

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