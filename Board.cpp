#include "Board.h"

Board::Board(int _offset,bool _isPlayer)
{
    isPlayer=_isPlayer;
    offset=_offset;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tiles[i][j] = Tile(i, j,offset);
        }
    }
}

void Board::Draw(sf::RenderWindow &window)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tiles[i][j].Draw(window);
        }
    }
}
