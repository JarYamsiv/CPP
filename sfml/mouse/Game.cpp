#include "headers/Game.h"

Game::Game():window(sf::VideoMode(640,480),"Mouse testing!!")
{

}

void Game::run()
{
   while (window.isOpen())
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

            
            //for a simple press use (not the drag effect) use  if(event.type == sf::Event::MouseButtonPressed)
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))//this also shows a dragiing effect
            {
                sf::Vector2i pos= sf::Mouse::getPosition(window);
                std::cout<<"pressed at "<<pos.x<<" "<<pos.y<<std::endl;
            }
        }

        window.clear();
        window.display();
    }
}

void Game::processEvents()
{

}

void Game::update()
{

}

void Game::render()
{

}