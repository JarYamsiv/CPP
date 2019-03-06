
CXXFLAGS += -std=c++11

#CXXFLAGS += -Wall -Wextra -pedantic-errors

#LDLIBS := $(shell pkg-config sfml-all --libs)
#SFML_DIR=/Volumes/DATA/SFML

# Location where SFML libraries are located
#LIBDIR=$(SFML_DIR)/lib

# Arguments to pass to the compiler
#CFLAGS=-I$(SFML_DIR)/include

# SFML (and other) libraries that need to be linked with
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

first:main.o Game.o
	g++ objects/main.o objects/Game.o $(LIBS) -o  main

main.o:main.cpp headers/Game.h
	g++ -c main.cpp -o objects/main.o

Game.o:Game.cpp headers/Game.h
	g++ -c Game.cpp -o objects/Game.o