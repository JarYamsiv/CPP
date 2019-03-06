EXECS=mpi_hello_world
MPICC?=mpicc

PC=4 #processor count 

all: ${EXECS}
	

mpi_hello_world: mpi_hello_world.c
	${MPICC} -o mpi_hello_world mpi_hello_world.c

clean:
	rm ${EXECS}	

run:
	mpiexec -np $(PC) mpi_hello_world
