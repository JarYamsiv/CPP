#include <SFML/Graphics.hpp>
#include <iostream>

class Game
{
public:
            Game();
    void    run();
private:
    void    processEvents();
    void    update();
    void    render();
    sf::RenderWindow window;
};

