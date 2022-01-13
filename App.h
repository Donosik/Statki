#ifndef STATKI_APP_H
#define STATKI_APP_H

#include <SFML/Graphics.hpp>
#include "Board.h"

class App
{
    sf::RenderWindow window;
    Board playerBoard;
    Board playerShootingBoard;
    Board computerBoard;
    Board computerShootingBoard;
    bool setting;
public:
    App();

    void Run();

    void Draw();

    void Events();
};


#endif STATKI_APP_H
