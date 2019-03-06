#ifndef _GAME_H
#define _GAEM_H
#include <SFML/Graphics.hpp>
#include "Grid.h"

#define WIDTH 640
#define HEIGHT 480

class Game{
public:
            Game();
            ~Game();
    void    run();
private:
    void    processEvents();
    void    update();
    void    render();
    void    KeyDownEvent(sf::Keyboard::Key key);
    sf::RenderWindow window;
    Grid    g;
    sf::Clock mclock;
    int frameLimit;
    bool running;
    sf::Text frameDisplay;
    sf::RectangleShape statusBar;
    sf::Font dispFont;
};
#endif