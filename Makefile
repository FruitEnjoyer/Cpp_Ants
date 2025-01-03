.PHONY: all main.o ant.o anthill.o

FLAGS = -Wall -std=c++17 -O2
CC = g++
OBJ = build/main.o build/ant.o build/anthill.o

all: main
	@echo "Clear temps ..."
	@rm -rf build/*.o
	@echo "Run app ..."
	@./build/main 

main: main.o ant.o anthill.o
	@echo "Build main ..."
	@$(CC) $(FLAGS) $(OBJ) -o build/main \
			-lsfml-graphics -lsfml-window -lsfml-system

main.o: src/main.cpp
	@echo "Build main.o ..."
	@$(CC) $(FLAGS) -c -o build/main.o src/main.cpp

ant.o: src/ant.cpp
	@echo "Build ant.o ..."
	@$(CC) $(FLAGS) -c -o build/ant.o src/ant.cpp

anthill.o: src/anthill.cpp
	@echo "Build anthill.o ..."
	@$(CC) $(FLAGS) -c -o build/anthill.o src/anthill.cpp