cmake_minimum_required (VERSION 2.6)
project(my-opengl4-program)
 
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -Wall -Wextra -march=native")
 
find_package(GLM REQUIRED)
find_package(SDL2 REQUIRED)
 
add_executable(my-opengl4-program
  glad/glad.c
  main.cpp
)
 
target_include_directories(my-opengl4-program PUBLIC
  ${GLM_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS}
)
 
target_link_libraries(my-opengl4-program
  ${SDL2_LIBRARIES}
)