.PHONY: all main.o ant.o anthill.o
.SILENT: all ant_colony main.o ant.o anthill.o

FLAGS = -Wall -std=c++17 -O2
CC = g++
OBJ = build/main.o build/ant.o build/anthill.o
MES_DONE = printf "\033[1;32m[Done]\n\033[0m"

all: ant_colony
	printf "\033[1;36mClear\033[0m  temps      "
	rm -rf build/*.o
	$(MES_DONE)
	printf "\033[1;36mRun\033[0m    ant_colony "
	./build/ant_colony 

ant_colony: main.o ant.o anthill.o
	printf "\033[1;36mBuild\033[0m  ant_colony "
	$(CC) $(FLAGS) $(OBJ) -o build/ant_colony \
			-lsfml-graphics -lsfml-window -lsfml-system
	$(MES_DONE)

main.o: src/main.cpp
	printf "\033[1;36mBuild\033[0m  main.o     "
	$(CC) $(FLAGS) -c -o build/main.o src/main.cpp
	$(MES_DONE)

ant.o: src/ant.cpp
	printf "\033[1;36mBuild\033[0m  ant.o      "
	$(CC) $(FLAGS) -c -o build/ant.o src/ant.cpp
	$(MES_DONE)

anthill.o: src/anthill.cpp
	printf "\033[1;36mBuild\033[0m  anthill.o  "
	$(CC) $(FLAGS) -c -o build/anthill.o src/anthill.cpp
	$(MES_DONE)