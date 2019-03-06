CC = g++
GDB = -g
OBJS = objects/main.o 
LIBS = -lGL -lGLU -lglut -lglfw -std=c++11

a.out : ${OBJS}
	${CC} ${GDB} ${OBJS} GLAD/glad.o ${LIBS} -o bin/main.out

objects/main.o: main.cpp
	${CC} -c main.cpp -o objects/main.o


clean:
	\rm a.out *.o *.dot
