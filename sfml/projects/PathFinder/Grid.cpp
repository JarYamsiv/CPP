#include "headers/Grid.h"
#include <math.h>

//#include<iostream>

Grid::Grid(float cellsize, int W, int H)
{
    this->cellsize = cellsize;
    brushSize = 3;
    width = W;
    height = H;
    x = (int)((float)W / cellsize);
    y = (int)((float)H / cellsize);

    mat = new int *[x];
    for (int i = 0; i < x; i++)
    {
        mat[i] = new int[y];
    }

    pmat = new int *[x];
    for (int i = 0; i < x; i++)
    {
        pmat[i] = new int[y];
    }

    sf::Vector2f sizeof_cell(cellsize, cellsize);
    cell.setSize(sizeof_cell);
}

Grid::~Grid()
{
    //std::cout<<"destroying"<<std::endl;
    for (int i = 0; i < x; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
    mat = 0;
    for (int i = 0; i < x; i++)
    {
        delete[] pmat[i];
    }
    delete[] pmat;
    pmat = 0;
}

void Grid::randomize(int seed)
{
    if (rand() % 2 == 0)
    {
        srand(seed);
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            mat[i][j] = rand() % 2;
        }
    }
}

void Grid::filterLonelyPixels()
{
    
}

void Grid::render(sf::RenderWindow *w)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cell_pos.x = i * cellsize;
            cell_pos.y = j * cellsize;
            cell.setPosition(cell_pos);
            if (mat[i][j] == 1)
            {
                (*w).draw(cell);
            }
        }
    }
}

void Grid::add_or_remove(int w, int h, bool choice)
{
    int i = w / (int)cellsize;
    int j = h / (int)cellsize;
    int r, theta, ii, jj;
    if (i > 0 && i < x && j > 0 && j < y)
    {
        /* mat[i-1][j-1] = (int)choice;
        mat[i-1][j] = (int)choice;
        mat[i-1][j+1] = (int)choice;
        mat[i][j-1] = (int)choice;
        mat[i][j] = (int)choice;
        mat[i][j+1] = (int)choice;
        mat[i+1][j-1] = (int)choice;
        mat[i+1][j] = (int)choice;
        mat[i+1][j+1] = (int)choice;*/
        for (r = 0; r <= brushSize; r++)
        {
            for (theta = 0; theta < 360; theta += 10)
            {
                ii = (int)(i + r * cos(theta));
                jj = (int)(j + r * sin(theta));
                mat[ii][jj] = (int)choice;
            }
        }
    }
}

void Grid::clearMat()
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            mat[i][j] = 0;
        }
    }
}

void Grid::InputHandle(sf::Event event, int clockValue)
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {

        case sf::Keyboard::R:
        {
            randomize(clockValue);
        }
        break;

        case sf::Keyboard::C:
        {
            clearMat();
        }
        break;

        case sf::Keyboard::I:
        {
            brushSize++;
        }
        break;

        case sf::Keyboard::K:
        {
            if(brushSize>0)
            {
                brushSize--;
            }
        }

        }
    }
}