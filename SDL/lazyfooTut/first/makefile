LINKERS = -lSDL2 -lGL
all : main_c
	g++ main.o -o main $(LINKERS)
	g++ lzf.o -o lzf $(LINKERS)
	g++ pxw.o -o pxw $(LINKERS)
main_c:
	g++ -c main.cpp -o main.o
	g++ -c lazyfooCode.cpp -o lzf.o
	g++ -c pixelwiseCode.cpp -o pxw.o