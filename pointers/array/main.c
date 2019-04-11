#include <stdio.h>
#include <stdlib.h>

/*
	This uses only ints I'm not sure whether the behaviour is same 
	with char...
*/


/*
	this function will create an array pointer and return it
*/
int * randomArrayBuilder(int n){
	int *arr =(int*)malloc(n* sizeof(int));
	int i=0;
	for (i = 0; i < n; ++i)
	{
		arr[i] = rand()%100;
	}
	return arr;
}



/*
	this will throw a segfault because we are recieving a copy of a 
	pointer and we are allocating onto it. but this is not on the actual pointer
	and hence later accessing the value from main will throw SIGSEV
*/
void randomArrayBuilder2(int n,int *arr)
{
	arr = (int*)malloc(n*sizeof(int));
	int i;
	for (i = 0; i < n; ++i)
	{
		arr[i] = rand()%100;
	}

}


/*
	this works fine as we are passing a pointer to a pointer and later 
	dereferencing it to reveal the original one and allocating memory onto it
*/
void randomArrayBuilder3(int n,int **arr){
	*arr = (int*)malloc(n*sizeof(int));
	int i;
	for (i = 0; i < n; ++i)
	{
		(*arr)[i] = rand()%100;
	}
}

void printPtr(int *p){
	/*
		the pointers will share the same value and it's also ok to 
		free them from inside a function.
		But be carefull while allocating pointers from inside a function
	*/
	printf("pointer inside function  %p  value is %d\n",p,*p );
	free(p);
}

int main()
{	

	int *arr = randomArrayBuilder(30);
	int i=0;
	printf("first array\n");
	for(i=0; i<30; i++){
		printf("%d ",arr[i] );
	}
	free(arr);
	printf("\n");


	// int *arr2;
	// randomArrayBuilder2(30,arr2);
	// for(i=0; i<30; i++){
	// 	printf("%d ",arr2[i] );
	// }
	// free(arr2);

	int *arr3;
	randomArrayBuilder3(30,&arr3);
	printf("second array\n");
	for(i=0; i<30; i++){
		printf("%d ",arr3[i] );
	}
	free(arr3);
	printf("\n");

	int *p =(int*) malloc(sizeof(int));
	*p = 4;
	printf(" pointer %p outside fun call , value is %d\n",p,*p );
	printPtr(p);

	/*Looks like no prob with freeing a null pointer*/
	int *q=NULL;
	free(q);

	/*
	this shows why randomArrayBuilder2 fails 
	valgrind will bitch about this though (because of the first print function,comment it )
	I'm not quite sure whether it will change after realloc
	calloc is nothing but a malloc with memset
	realloc will also cause the same problem as of randomArrayBuilder2 if not
	used with those methods (ie, have to pass an int**)
	*/
	int *r;
	printf("before alloc: r is a pointer with value %p\n",r );
	r =(int*) malloc(10*sizeof(int));
	printf("after alloc: r is a pointer with value %p\n",r );
	r = (int*)realloc(r,200*sizeof(int));
	printf("after realloc: r is a pointer with value %p\n",r );
	free(r);

	return 0;
}
		
