CC := g++
FLS := engine
OBJ := $(patsubst %,%.o,$(FLS))
OBJECTS := $(patsubst %,objects/%.o,$(FLS))
SRC := $(patsubst %,%.cpp,$(FLS))

LINKERS := -lSDL2 -lpthread -lcudart

all:${OBJ} main_c cuda_cu
	g++ objects/main.o objects/cudaprog.o ${OBJECTS} ${LINKERS} -o bin/app

main_c:
	${CC} -c main.cpp -o objects/main.o

cuda_cu:src/cudaprog.cu
	nvcc -c src/cudaprog.cu -o objects/cudaprog.o

%.o:headers/%.h
	${CC} -c src/$*.cpp -o objects/$*.o