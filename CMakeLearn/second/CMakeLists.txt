cmake_minimum_required(VERSION 2.6)
project(Second)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories("${PROJECT_SOURCE_DIR}/headers")

set(SOURCES src/func.cpp)
file(GLOB SOURCES
	"src/*.cpp"
	"*.cpp"
	)


add_executable(hello ${SOURCES})


#run using cmake -H. -Bbuild
#make usingm cmake --build build -- -j3
