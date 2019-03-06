#include <GL/glut.h>
#include "objects.h"
#ifndef WIDTH
#define WIDTH 1600
#endif
#ifndef HEIGHT
#define HEIGHT 900
#endif




Box b(100.0,100.0);
void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    b.display();
    glFlush();
}

static void Key(unsigned char key, int x, int y)
{
    //b.key(key,x,y);
    if(key==27)exit(0);

    //glutPostRedisplay();
}

static void Keyup(unsigned char key, int x, int y)
{
    b.key(key,x,y);
    //glutPostRedisplay();
}

void Timer(int v)
{
        b.oscillate();
        glutTimerFunc(1,Timer,1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world :D");


    glutKeyboardFunc(Key);
    glutKeyboardUpFunc(Keyup);
    glutDisplayFunc(displayMe);
    glutIdleFunc(displayMe);
    glutTimerFunc(1,Timer,1);
    glutMainLoop();
    return 0;
}
