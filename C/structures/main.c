#include<stdio.h>
#include<stdlib.h>

#define class_(x) typedef struct x

#define fun(type,name,...) type (*name)(__VA_ARGS__)

#define alo(x,n) (x*)calloc(sizeof(x),n)

class_(node){
	int value;
	fun(int,p,struct node*);
}node;




int node_double(node* x){
	return 2*x->value;
}

int main(){	
	node n;
	n.value = 10;
	n.p = &node_double;
	int *p = alo(int,10);
	free(p);
	return 0;
}
		
