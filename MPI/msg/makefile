EXECS=main
MPICC?=mpicc

PC=4 #processor count 

all: ${EXECS}
	

main: main.c
	${MPICC} -o main main.c

clean:
	rm ${EXECS}	

run:
	mpiexec -np $(PC) main
