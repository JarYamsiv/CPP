cmake_minimum_required(VERSION 2.6)
project(headerTest)
file(GLOB source_files
	"*.h"
	"*.cpp"
	"headers/*.h"
	"src/*.cpp"	
)
add_executable(mainOut ${source_files})

