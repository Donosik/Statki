#include "Board.h"

Board::Board(bool _isShooting)
{
    isShooting = _isShooting;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            array[i][j] = "*";
        }
    }
    normal = sf::Color(0, 0, 0);
    shooted = sf::Color(255, 0, 0);
    setted = sf::Color(0, 255, 0);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            outerShape[i][j].setPosition(i*20+10,j*20+10);
            outerShape[i][j].setFillColor(sf::Color(255,255,255));
        }
    }
}

#include <iostream>

void Board::Draw(sf::RenderWindow &window)
{
    //TODO: DEBUG
    /*
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
     */
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            window.draw(outerShape[i][j]);
        }
    }
}