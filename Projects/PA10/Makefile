# compiler

CC=g++

all: main

main: testDriver.cpp listA.o listN.o
	g++ testDriver.cpp listA.o listN.o -o testDriver

listA.o: listA.cpp
	g++ -c listA.cpp

listN.o: listN.cpp
	g++ -c listN.cpp

clean: rm -rf *.o main