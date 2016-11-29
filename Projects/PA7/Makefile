# the compiler to use
CC=g++

all: main

main: main.cpp Project7.o
	g++ main.cpp Project7.o -o main

Project7.o: Project7.cpp
	g++ -c Project7.cpp

clean: rm -rf *.o main
