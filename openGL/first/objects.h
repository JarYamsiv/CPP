#ifndef WIDTH
#define WIDTH 1600
#endif
#ifndef HEIGHT
#define HEIGHT 900
#endif
#include <math.h>
#include <iostream>
class Box{
private:
  float x,y,xn,yn;
  float width,height;
  float widthn,heightn;
  float t;
  float ty;
public:
  Box(float w,float h)
  {
    //for opengl all position definig variables vary from -1.0 to 1.0 of which (0.0,0.0) representts the origin whcich
      //is situated at the center and further measurements are made according to cartecian co-ordinate measuring methodes
    height=h;
    width=w;
    x=-1.0;y=0.0;
    t=0;ty=0;
    widthn=width/(WIDTH/2);
    heightn=height/(HEIGHT/2);
  }
  void display()
  {
    xn=x/(WIDTH/2);
    yn=y/(HEIGHT/2);
    /*  glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(0.5,0.0,0.0);
        glVertex3f(0.5,0.5,0.0);
        glVertex3f(0.0,0.5,0.5);
      glEnd();*/
      glBegin(GL_QUADS);
      glVertex2f(xn,yn+heightn);
      //Left - Bottom
      glVertex2f(xn+widthn,yn+heightn);
      glVertex2f(xn+widthn,yn);
      glVertex2f(xn,yn);
      glEnd();
  }
  void key(unsigned char key, int x_arg,int y_arg)
  {
      if(key=='1')
      {
        if(ty<2*M_PI)
        {
          ty+=0.05;
        }
        else
        {
          ty=0;
        }
        y=100*sin(ty);
      }
  }
  void oscillate()
  {
    if(t<2*M_PI)
    {
      t+=0.005;
    }
    else
    {
      t=0;
    }
    x=100*sin(t);
  }
};
