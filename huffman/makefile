all:readwrite


readwrite:readwrite.cpp
	g++ readwrite.cpp -o rw -std=c++17 -lm

huff:huffman.cpp
	g++ huffman.cpp -o h -std=c++17 -lm

test:all
	./rw read yeet.txt
	diff yeet.txt decompressed/test.txt
		
