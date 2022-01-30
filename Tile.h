#ifndef STATKI_TILE_H
#define STATKI_TILE_H

#include <SFML/Graphics.hpp>

class Tile
{
    enum class StatusShip
    {
        EMPTY,
        TAKEN
    };

    enum class StatusShoot
    {
        EMPTY,
        SHOOTED
    };
    sf::RectangleShape shape;
    float size;
    int xPos;
    int yPos;
    float scale;
    StatusShip statusShip;
    StatusShoot statusShoot;
public:
    Tile();

    Tile(int x, int y, int offset);

    void Draw(sf::RenderWindow &window);

    void SetStatus(int length);

    void SetHoovered();

    bool IsTaken();

    void SetShooted(bool hit);

    bool IsShooted();
};


#endif STATKI_TILE_H
