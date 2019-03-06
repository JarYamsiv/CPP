#ifndef _GRID_H
#define _GRID_H
#include <cstdlib>
#include <SFML/Graphics.hpp>
class Grid
{
public:
            Grid(float cellsize,int W,int H);
            ~Grid();
    void    randomize(int seed);
    int     **mat;
    int     **pmat;
    void    filterLonelyPixels();
    void    render(sf::RenderWindow* w);  
    void    add_or_remove(int x,int y,bool choice);
    void    clearMat();
    void    InputHandle(sf::Event event,int clockValue);
private:
    int                 x,y;
    int                 width,height;
    float               cellsize;
    int                 brushSize;
    sf::RectangleShape  cell;
    sf::Vector2f        cell_pos;
};

#endif