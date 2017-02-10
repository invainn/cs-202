#include <iostream>
#include <fstream>

#include "listA.h"
#include "listN.h"

using namespace std;

void swap(ListN&);
void bubbleSort(ListN&, int);
int recursiveBinarySearch(ListA&, int, int, int);

int main() {

	ifstream DataFile;

	DataFile.open("datafile");

	int count = 0;
	int tempNumber = 0; // this holds an integer that is being placed into the list

	DataFile >> count;

	ListN listNode; // intializes list to count

	for(int i = 0; i < count; i++) {
		DataFile >> tempNumber;
		listNode.insertAfter(tempNumber);
	}

	DataFile.close();

	cout << "Unsorted List" << endl;
	cout << listNode << endl;
	cout << endl;

	listNode.goToBeginning();
	bubbleSort(listNode, count);
	cout << "Sorted List" << endl;
	cout << listNode << endl;
	cout << endl;

	// sorting begins
	ListA listArray(count);

	for(int i = 0; i < count; i++) {
		int temp  = listNode.getAtCursor();
		listArray.insertAfter(temp);
		listNode.goToNext();
	}
	listArray.goToBeginning();

	int key = 0;
	cout << "What value would you like to find?" << endl;
	cin >> key;
	cout << endl;


	int result = recursiveBinarySearch(listArray, key, 0, count);

	if(result != -1) {
		cout << "Found " << key << " at index " << result << endl;
	} else {
		cout << "Unable to find key in list" << endl;
	}

	return 0;
}

// the behavior of this function will swap cursor and the next element 
void swap(ListN& listN) {
	int temp = listN.getAtCursor();
	listN.remove();
	int temp2 = listN.getAtCursor();
	listN.remove();
	listN.insertBefore(temp); // inserting in this order because cursor will be on the first insertBefore's element
	listN.insertBefore(temp2);
}

void bubbleSort(ListN& listN, int count) {
	bool hasSwapped = true;

	while(hasSwapped) {
		hasSwapped = false;
		for(int i = 0; i < count-1; i++) {
			// we will use two integer variables to store element values and then compare to each other
			int temp  = listN.getAtCursor();
			listN.goToNext();
			int temp2 = listN.getAtCursor();
			listN.goToPrior();
			if(temp > temp2) {
				swap(listN);
				hasSwapped = true;
			}

			listN.goToNext();
		}
		listN.goToBeginning();
	}
}

int recursiveBinarySearch(ListA& listA, int key, int min, int max) {
	if(min > max) {
		return -1;
	}

	int pivot = (min+max)/2;

	for(int i = 0; i < pivot; i++) {
		listA.goToNext();
	}

	int pivotValue = listA.getAtCursor();

	if(pivotValue == key) {
		return pivot;
	} else if(pivotValue < key) {
		listA.goToBeginning();
		return recursiveBinarySearch(listA, key, pivot+1, max);
	} else {
		listA.goToBeginning();
		return recursiveBinarySearch(listA, key, min, pivot-1);
	}
}