#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct arr
{
	void* ptr;
	uint64_t size;
	
}arr;

void create_arr(int n,arr *a)
{
	a->ptr = malloc(n*sizeof(int));
	a->size = n;
}

void free_arr(arr* a){
	free(a->ptr);
	a->size = 0;
}

void rand_int_populate(arr* a){
	int i=0;
	for(i=0; i<a->size; i++){
		((int*)a->ptr)[i] = rand()%100;
	}
}

void print_arr(arr* a){
	int i=0;
	for(i=0; i<a->size; i++){
		printf("%d ",((int*)a->ptr)[i] );
	}
}

int main()
{	
	arr a;
	create_arr(10,&a);
	rand_int_populate(&a);
	print_arr(&a);
	free_arr(&a);
	printf("\n");
	return 0;
}
		
