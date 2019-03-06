
#include <stdio.h>

int main(int argc, char *argv[])
{
  int N = 10;

  printf("the arguments are:\n");
  for (int i = 0; i < argc; ++i) {

    printf("%s\n",argv[i] );
    
  }

  
  for (int j = 0; j < N; ++j) {
    printf("the value of j is %d \n",j); 
  }
  
  return 0;
}

