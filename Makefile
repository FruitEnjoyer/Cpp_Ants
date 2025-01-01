.PHONY: all

FLAGS = -Wall -std=c++17 -O0

GXX = g++

all: main
	@echo "Clear temps ..."
	@rm -rf build/*.o
	@echo "Run app ..."
	@./build/main 

main: main.o
	@echo "Build main ..."
	@$(GXX) $(FLAGS) \
			build/main.o \
			-o build/main \
			-lsfml-graphics -lsfml-window -lsfml-system


main.o: src/main.cpp
	@echo "Build main.o ..."
	@$(GXX) $(FLAGS) -c -o build/main.o src/main.cpp

