CC = g++
GDB = -g
OBJS = objects/main.o objects/P5.o
LIBS = -lGL -lGLU -lglut -lglfw -lGLEW 

a.out : ${OBJS}
	${CC} ${GDB} ${OBJS} ${LIBS} -o bin/main.out

objects/main.o: main.cpp
	${CC} -c main.cpp -o objects/main.o

objects/P5.o: src/P5.cpp
	${CC} -c src/P5.cpp -o objects/P5.o


clean:
	\rm a.out *.o *.dot
