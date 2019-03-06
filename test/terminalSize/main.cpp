#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

int main (int argc, char **argv)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    //std::cout<<"\f";
    std::cout << "\e[A";
    std::cout << "\e[A\r\e[0K";
    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);
    return 0;  // make sure your main returns int
}