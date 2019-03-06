#include<stdio.h>
//#include<iomanip.h>

void grid(int n);
int main()
{
	grid(9);
	printf("\n");
	return 0;
}
void grid(int n)
{
	static int count = 2 ;
	if(n==0)return;
	int k = 0;
	int i=0;
	printf("%d",k);
	grid(n-1);
	printf("\n");
	//printf(" %d",count++);
	//setw(n);
	for(i=0;i<(9-n);++i)
	{	printf(" ");	}
	k = 1;
	printf("%d",k);
	grid(n-1);
	
}
