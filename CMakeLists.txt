cmake_minimum_required(VERSION 3.16)
project(ant_colony VERSION 0.1)
set(CMAKE_C_STANDARD 11)

set(SOURCES src/main.c src/ant.c src/anthill.c src/pheromone.c)

add_executable(ants ${SOURCES})

target_link_libraries(ants libSDL2-2.0.so)