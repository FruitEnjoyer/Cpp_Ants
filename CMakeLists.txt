cmake_minimum_required(VERSION 3.16)
project(ants VERSION 0.1)
set(CMAKE_C_STANDARD 11)

set(SOURCES src/main.cpp src/ant.c src/anthill.c src/pheromone.cpp)

add_executable(main ${SOURCES})

target_link_libraries(main libSDL2-2.0.so)