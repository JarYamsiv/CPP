#include <mpi.h>
#include <stdio.h>

int rand_array(int *,int);

int main()
{	
	MPI_Init(NULL,NULL);
	int worldsize,worldrank;

	MPI_Comm_size(MPI_COMM_WORLD,&worldsize);
	MPI_Comm_rank(MPI_COMM_WORLD,&worldrank);


	

	if(worldrank == 0){

		int arr_size;
		int *arr;


		printf("enter size\n");
		scanf("%d",&arr_size);
		arr = (int*)malloc(arr_size*sizeof(int));
		rand_array(arr,arr_size);



		MPI_Bcast(&arr_size,1,MPI_INT,0,MPI_COMM_WORLD);

		free(arr);
	}
	else{
		int arr_size,my_arr_size;
		int* arr;

		MPI_Bcast(&arr_size,1,MPI_INT,0,MPI_COMM_WORLD);

		my_arr_size = arr_size/worldsize;
		arr = (int*)malloc(sizeof(int)*my_arr_size);

		printf("i'm %d of %d arr_size %d\n",worldrank,worldsize,arr_size );
		free(arr);
	}

	

	


	

	MPI_Finalize();
	return 0;
}

int rand_array(int *arr, int size){
	int i;
	for (i=0; i<size; i++){
		arr[i] = rand()%100;
	}
}
		
