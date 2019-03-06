#gcc -o hellomake hellomake.c hellofunc.c -I = usual compilation methode
CC=g++
LDLIBS := $(shell pkg-config sfml-all --libs)
#the first parameter represents the name of whatever we are doin like if i type
#make first it will run the first set and generate a.out
#and similiarly if i run make second it'll run the second one and generate b.out (now ive removed it
#it's actually the same as first: except that it has -o b instead of -o
#i still haven't quite understood the use of that hellomake.c and hellofunc.c after first:

first: hellomake.cpp hellofunc.cpp 
	$(CC) -o a hellomake.cpp hellofunc.cpp
