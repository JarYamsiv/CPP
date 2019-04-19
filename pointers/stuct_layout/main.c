#include <stdio.h>
#include <stdint.h>

/*
	no clue what this program acttually does but generates a random 
	number each time is run
*/


typedef struct A
{
	char x,y,z,w;		
}A;

void print(void* arg){
	char a = (char)arg;
	printf("a->x is %d \n",a );
}

int main()
{
	A a;
	a.x = 0;
	a.y = 0;
	a.z = 1;
	a.w = 1;

	print((void*)&a);
	return 0;
}
		
