#ifndef STATKI_SHOWINGBOARD_H
#define STATKI_SHOWINGBOARD_H

#include "Board.h"

class ShowingBoard : public Board
{
public:
    ShowingBoard(bool _isPlayer = true);

    void SetShip(int xPos1, int yPos1, int xPos2, int yPos2);

    bool IsShip(int x,int y);

    bool isShooted(int x,int y);

    void SetShooted(int x,int y,bool hit);
private:
    void SetShipsAsComputer();
};


#endif //STATKI_SHOWINGBOARD_H
