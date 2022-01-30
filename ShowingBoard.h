#ifndef STATKI_SHOWINGBOARD_H
#define STATKI_SHOWINGBOARD_H

#include "Board.h"

class ShowingBoard : public Board
{
public:
    ShowingBoard(bool _isPlayer = true);

    void Set(int x, int y) override;

    void SetShip(int xPos1, int yPos1, int xPos2, int yPos2);

};


#endif //STATKI_SHOWINGBOARD_H
