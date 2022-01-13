#ifndef STATKI_BOARD_H
#define STATKI_BOARD_H

#include <string>
#include <SFML/Graphics.hpp>

class Board
{
    std::string array[10][10];
    sf::RectangleShape outerShape[10][10];
    sf::RectangleShape innerShape[10][10];
    sf::Color normal;
    sf::Color shooted;
    sf::Color setted;
    bool isShooting;
public:
    Board(bool _isShooting);

    void Draw(sf::RenderWindow &window);
};


#endif STATKI_BOARD_H
