#include "hellomake.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
  // call a function in another file
  myPrintHelloMake();
  std::cout<<"hi it's a change,new change after removing something from makefile";
  return(0);
}
