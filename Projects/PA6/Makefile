# the compiler to use
CC=g++

all: main

main: main.cpp Agency.o
	g++ main.cpp Agency.o -o main

Agency.o: Agency.cpp
	g++ -c Agency.cpp

clean: rm -rf *.o main
