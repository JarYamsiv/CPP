#include "headers/Game.h"

Game::Game():
window(sf::VideoMode(640,480),"Mouse testing!!"),
buffer(),
bufferSprite(),
pixTex()
{
    buffer.create(640,480,sf::Color(0,0,0));
    pixels = new sf::Uint8[640*480*4];

    for(int i=0; i<640; i++)
    {
        for(int j=0; j<480; j++)
        {
            for(int k=0; k<4; k++)
            {
                pixels[(i*640+j)*4+k]=255;
            }
        }
    }

    pixTex.update(pixels);
    //bufferSprite.SetImage(buffer);
    bufferSprite.setTexture(pixTex);
}

void Game::run()
{
   while (window.isOpen())
    {
        
        processEvents();
        update();
        render();
        
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();                
            }

        }
}

void Game::update()
{

}

void Game::render()
{
    window.clear();
    window.draw(bufferSprite);
    window.display();
}

Game::~Game()
{
    delete [] pixels;
}