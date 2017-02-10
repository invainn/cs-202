A_OBJS=listA.o testdriver.o
N_OBJS=listN.o testdriver.o

# make sure your implementation files match these names
ARRAY_CPP=listA.cpp
NODE_CPP=listN.cpp

EXEC=arrayBased nodeBased

all: 
	@echo "-----------------------------------"
	@echo "for array based, type: make array"
	@echo "for node based, type: make node"
	@echo "-----------------------------------"

array: $(A_OBJS) 
	g++ $(A_OBJS) -o arrayBased
	rm -f *.o

node: $(N_OBJS)
	g++ $(N_OBJS) -o nodeBased
	rm -f *.o

testdriver.o: testdriver.cpp
	g++ -c testdriver.cpp -include $(HEADER) -o testdriver.o
	
listN.o: $(NODE_CPP)
	$(eval HEADER = listN.h)
	@echo "making linked list"
	g++ -c $(NODE_CPP) -o listN.o
	
listA.o: $(ARRAY_CPP)
	$(eval HEADER = listA.h) 
	@echo "making array based list"
	g++ -c $(ARRAY_CPP) -o listA.o

clean:
	rm -f *.o $(EXEC)