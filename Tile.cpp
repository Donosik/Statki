#include "Tile.h"

Tile::Tile()
{
    xPos = 1;
    yPos = 1;
    size = 60;
    scale = 0.9;
    shape.setSize(sf::Vector2f(size * scale, size * scale));
    shape.setPosition(xPos * size, yPos * size);
    shape.setFillColor(sf::Color::Blue);
}

Tile::Tile(int x, int y, int offset)
{
    xPos = x;
    yPos = y;
    size = 60;
    scale = 0.9;
    shape.setSize(sf::Vector2f(size * scale, size * scale));
    shape.setPosition(xPos * size + offset + (size - (size * scale)) / 2, yPos * size + 50 + (size - (size * scale)) / 2);
    shape.setFillColor(sf::Color(0, 0, 255));
    status = Status::EMPTY;
}

void Tile::Draw(sf::RenderWindow &window)
{
    window.draw(shape);
}

void Tile::SetStatus(int length)
{
    sf::Color shipColor;
    switch (length)
    {
        case 1:
        {
            shipColor = sf::Color::Green;
        }
            break;
        case 2:
        {
            shipColor = sf::Color::Yellow;
        }
            break;
        case 3:
        {
            shipColor = sf::Color::Cyan;
        }
            break;
        case 4:
        {
            shipColor = sf::Color::Red;
        }
            break;
        default:
        {
            shipColor = sf::Color::Black;
        }
    }
    shape.setFillColor(shipColor);
}

void Tile::SetHoovered()
{
    if (shape.getFillColor() == sf::Color(128, 128, 128))
    {
        shape.setFillColor(sf::Color::Blue);
    }
    else
    {
        shape.setFillColor(sf::Color(128,128,128));
    }
}

bool Tile::IsTaken()
{
    return status == Status::TAKEN;
}