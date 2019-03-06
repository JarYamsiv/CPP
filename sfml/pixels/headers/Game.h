#include <SFML/Graphics.hpp>
#include <iostream>

class Game
{
public:
            Game();
            ~Game();
    void    run();
private:
    void    processEvents();
    void    update();
    void    render();
    sf::RenderWindow 	window;
    sf::Image 			buffer;
    sf::Sprite 			bufferSprite;
    sf::Texture			pixTex;
    sf::Uint8			*pixels;
};

