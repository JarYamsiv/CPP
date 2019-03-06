#include <SFML/Graphics.hpp>

int main()
{
    sf::RendermWindow mWindow(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (mWindow.isOpen())
    {
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mWindow.close();

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                mWindow.close();                
            }
        }

        mWindow.clear();
        mWindow.draw(shape);
        mWindow.display();
    }
    

    return 0;
}
