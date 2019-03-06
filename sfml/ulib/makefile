all:
	g++ -c main.cpp -I./SFML-2.4.2/include
	g++ main.o -o sfml-app -L./SFML-2.4.2/lib -lsfml-graphics -lsfml-window -lsfml-system

run:
	export LD_LIBRARY_PATH=./SFML-2.4.2/lib && ./sfml-app