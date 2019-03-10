#include <mpi.h>   /* PROVIDES THE BASIC MPI DEFINITION AND TYPES */
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  
  int my_rank; 
  int partner;
  int size, i,t;
  char greeting[100];
  MPI_Status stat;
  
  MPI_Init(&argc, &argv); /*START MPI */
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); /*DETERMINE RANK OF THIS PROCESSOR*/
  MPI_Comm_size(MPI_COMM_WORLD, &size); /*DETERMINE TOTAL NUMBER OF PROCESSORS*/
  
  
  sprintf(greeting, "Hello world: processor %d of %d\n", my_rank, size);
  
  /* adding a silly conditional statement like the
     following graphically illustrates "blocking" and
     flow control during program execution
     
     if (my_rank == 1) for (i=0; i<1000000000; i++) t=i;
     
  */
  
  if (my_rank ==0) {
    fputs(greeting, stdout);
    for (partner = 1; partner < size; partner++){
      
      MPI_Recv(greeting, sizeof(greeting), MPI_BYTE, partner, 1, MPI_COMM_WORLD, &stat);
      fputs (greeting, stdout);
      
    }
  }
  else {
    MPI_Send(greeting, strlen(greeting)+1, MPI_BYTE, 0,1,MPI_COMM_WORLD);
  }
  
  
  
  if (my_rank == 0) printf("That is all for now!\n");
  MPI_Finalize();  /* EXIT MPI */
  
}