CPP_FILES = $(wildcard *.cpp)
OUT_FILES = $(patsubst %.cpp, %.o, $(CPP_FILES))
OUT_FILE_DIR = $(patsubst %.o, objects/%.o, $(OUT_FILES))

all : $(OUT_FILES)
	@echo CPP_FILES : $(CPP_FILES)
	g++ $(OUT_FILE_DIR) -o main 
%.o : %.cpp
	g++ -c $<  -o objects/$@

cleanobj:
	rm -f objects/*.o

cleanall:
	rm -f objects/*.o
	rm -f *.o
	rm -f main
