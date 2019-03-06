#specify minimum required version
cmake_minimum_required(VERSION 2.6)

#project's name
project(Tutorial)

#set output folder
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BIANRY_DIR})

#to include the followinfg directory
include_directories("${PROJECT_SOURCE_DIR}")


add_executable(hello test.cpp)

