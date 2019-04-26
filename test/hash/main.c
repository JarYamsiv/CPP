#include <stdio.h>

struct msg_on_send
{
int x;
int y; 
};

void USARTWrite(const void *object, size_t size)    
{
    const unsigned char *byte;
      for ( byte = object; size--; ++byte )                                     
      {   
          printf("%02X", *byte);
      }   
      putchar('\n');
}

int main (int argc, char**argv)
{
    struct msg_on_send myMsg;
    myMsg.x = 0;
    myMsg.y = 789;
    unsigned char* ptr= (unsigned char*)&myMsg;

    USARTWrite(ptr, sizeof(myMsg));

    return 0;
}