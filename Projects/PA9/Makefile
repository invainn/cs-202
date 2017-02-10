CC = g++
CPPFLAGS = -Wall
STACK_OBJS = stackA.o stackN.o
QUEUE_OBJS = queueA.o queueN.o
EXEC = testProgram


all: testDriver.o $(STACK_OBJS) $(QUEUE_OBJS)
	$(CC) $(CPPFLAGS) testDriver.o $(STACK_OBJS) $(QUEUE_OBJS) -o $(EXEC)

testDriver.o: testDriver.cpp $(STACK_OBJS) $(QUEUE_OBJS)
	$(CC) $(CPPFLAGS) -c testDriver.cpp -o testDriver.o

stackA.o: stackA.cpp
	$(CC) $(CPPFLAGS) -c stackA.cpp -o stackA.o

stackN.o: stackN.cpp
	$(CC) $(CPPFLAGS) -c stackN.cpp -o stackN.o

queueA.o: queueA.cpp
	$(CC) $(CPPFLAGS) -c queueA.cpp -o queueA.o

queueN.o: queueN.cpp
	$(CC) $(CPPFLAGS) -c queueN.cpp -o queueN.o

clean:
	rm -f *.o $(EXEC)