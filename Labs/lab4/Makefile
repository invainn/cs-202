ila4: main stack
	g++ -g main stack -o ila4

main: main.cpp Stack.h
	g++ -c main.cpp -o main

stack: Stack.cpp Stack.h
	g++ -c Stack.cpp -o stack

clean:
	rm ila4 main stack
