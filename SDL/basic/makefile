CC := g++
FLS := engine
OBJ := $(patsubst %,%.o,$(FLS))
OBJECTS := $(patsubst %,objects/%.o,$(FLS))
SRC := $(patsubst %,%.cpp,$(FLS))

LINKERS := -lSDL2 -lpthread

all:${OBJ} main_c
	g++ objects/main.o ${OBJECTS} ${LINKERS} -o bin/app

main_c:
	${CC} -c main.cpp -o objects/main.o

%.o:headers/%.h
	${CC} -c src/$*.cpp -o objects/$*.o