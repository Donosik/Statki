#ifndef STATKI_TILE_H
#define STATKI_TILE_H

#include <SFML/Graphics.hpp>

class Tile
{
    enum Status
    {
        EMPTY,
        TAKEN,
        SHOOTED
    };

    sf::RectangleShape shape;
    float size;
    int xPos;
    int yPos;
    float scale;
    Status status;
public:
    Tile();

    Tile(int x, int y, int offset);

    void Draw(sf::RenderWindow &window);

    void SetStatus(int length);

    void SetHoovered();

    bool IsTaken();
};


#endif STATKI_TILE_H
