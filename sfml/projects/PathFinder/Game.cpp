#include "headers/Game.h"
#include "headers/Grid.h"
#include <ctime>
#include <string>

Game::Game():window(sf::VideoMode(WIDTH,HEIGHT+30),"cellular automata-Game of life"),g(1.0f,WIDTH,HEIGHT)
{
    frameLimit=60;
    running=false;

    sf::Color statusBarColor(25,25,25);
    window.setFramerateLimit(frameLimit);
    sf::Vector2f statusBarPosition(0,HEIGHT);
    sf::Vector2f statusBarSize(WIDTH,30);
    statusBar.setFillColor(statusBarColor);
    statusBar.setPosition(statusBarPosition);
    statusBar.setSize(statusBarSize);
    
    frameDisplay.setFont(dispFont);
    frameDisplay.setString((char)frameLimit);
    frameDisplay.setColor(sf::Color::Cyan);
}

Game::~Game()
{
    
}

void Game::run()
{
    
    g.randomize((int)time(0));
    window.setKeyRepeatEnabled(false);
    while(window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::KeyDownEvent(sf::Keyboard::Key key)
{
    switch(key)
    {
        case sf::Keyboard::Escape:
        {
            window.close(); 
        }break;


        case sf::Keyboard::Up:
        {
            frameLimit+=5;
            window.setFramerateLimit(frameLimit);
            //frameDisplay.setString(std::to_string(frameLimit));
        }break;

        case sf::Keyboard::Down:
        {
            if(frameLimit>5)
            frameLimit-=5;
            window.setFramerateLimit(frameLimit);
            //frameDisplay.setString(std::to_string(frameLimit));
        }break;

        case sf::Keyboard::S:
        {
            running=!running;
        }break;

    }
   
}


void Game::processEvents()
{
    sf::Event event;
        while (window.pollEvent(event))
        {
            g.InputHandle(event,mclock.getElapsedTime().asMilliseconds());
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed)
            {
                KeyDownEvent(event.key.code);
                
                              
            }
            
            //for a simple press use (not the drag effect) use  if(event.type == sf::Event::MouseButtonPressed)
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))//this also shows a dragiing effect
            {
                sf::Vector2i pos= sf::Mouse::getPosition(window);
                //std::cout<<"pressed at "<<pos.x<<" "<<pos.y<<std::endl;
                g.add_or_remove(pos.x,pos.y,true);
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Right))//this also shows a dragiing effect
            {
                sf::Vector2i pos= sf::Mouse::getPosition(window);
                //std::cout<<"pressed at "<<pos.x<<" "<<pos.y<<std::endl;
                g.add_or_remove(pos.x,pos.y,false);
            }
        }
}

void Game::update()
{
    
}

void Game::render()
{
    window.clear();
    g.render(&window);
    window.draw(frameDisplay);
    window.draw(statusBar);
    window.display();
}