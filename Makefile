.PHONY: all

FLAGS = -Wall -std=c++17 -O0

GXX = g++

all: main
	@echo "Clear temps ..."
	@rm -rf build/*.o
	@echo "Run app ..."
	@./build/main 

main: main.o ant.o
	@echo "Build main ..."
	@$(GXX) $(FLAGS) \
			build/main.o build/ant.o\
			-o build/main \
			-lsfml-graphics -lsfml-window -lsfml-system

main.o: src/main.cpp
	@echo "Build main.o ..."
	@$(GXX) $(FLAGS) -c -o build/main.o src/main.cpp

ant.o: src/ant.cpp src/ant.hpp
	@echo "Build ant.o ..."
	@$(GXX) $(FLAGS) -c -o build/ant.o src/ant.cpp
