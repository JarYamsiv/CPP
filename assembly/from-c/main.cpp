#include <stdio.h>
#include <string.h>
int main(int argc,char** argv)
{
  if(argc<2)
    {
      printf("usage main key...\n");
    }
  else
    {
      if(strcmp(argv[1],"meow")==0)
	{
	  printf("access granted\n");
	}
      else
	{
	  printf("access denied\n");
	}
    }
  return 0;
	
}
		
