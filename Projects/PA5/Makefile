# the compiler to use
CC=g++

all: main

main: main.cpp string.o
	g++ main.cpp string.o -o main

string.o: string.cpp
	g++ -c string.cpp

clean: rm -rf *.o main
